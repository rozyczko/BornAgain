// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/RealSpaceWidgets/RealSpaceBuilderUtils.h
//! @brief     Defines RealSpaceBuilderUtils namespace
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "RealSpace2DParacrystalUtils.h"
#include "FTDistributions2D.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "Lattice2D.h"
#include "RealSpaceCanvas.h"

namespace
{
void resizeLatticePositions(std::vector<std::vector<double>>& lattice_positions, double l1,
                            double l2, double layer_size)
{
    // Estimate the limit n1 and n2 of the integer multiple j and i of the lattice vectors l1 and l2
    // required for populating particles correctly within the 3D model's boundaries
    int n1 = 0, n2 = 0;
    n1 = l1 == 0.0 ? 2 : static_cast<int>(layer_size * 2 / l1);
    n2 = l2 == 0.0 ? 2 : static_cast<int>(layer_size * 2 / l2);

    n1 = std::max(n1, n2);

    lattice_positions.resize(static_cast<size_t>((2 * n1 + 1) * (2 * n1 + 1)));
    for (auto& it : lattice_positions) {
        it.resize(2);
    }

    lattice_positions[0][0] = 0.0; // x coordinate of reference particle - at the origin
    lattice_positions[0][1] = 0.0; // y coordinate of reference particle - at the origin
}

void findLatticePositionsIndex(size_t& index, size_t& index_prev, int i, int j, int size,
                               double l_alpha)
{
    index = static_cast<size_t>(i * (2 * size + 1) + j);

    if (std::sin(l_alpha) == 0) // along l1
    {
        // particles along +l1 stored every odd iter (e.g. 1,3,5...) index of lattice_positions
        // particles along -l1 stored every even iter (e.g. 2,4,6...) index of lattice_positions
        index_prev = static_cast<size_t>(i * (2 * size + 1));
        if (j - 2 > 0)
            index_prev = index - 2;
    } else // along l2
    {
        // particles along +l2/-l2 stored every (odd/even iter)*(2*n1+1) index of lattice_positions
        index_prev = static_cast<size_t>(j);
        if (i - 2 > 0)
            index_prev = index - static_cast<size_t>(2 * (2 * size + 1));
    }
}

std::pair<double, double> computePositionAlongPositiveLatticeVector(
    const size_t index_prev, std::vector<std::vector<double>>& lattice_positions,
    const IFTDistribution2D* pdf, double l, double l_xi, double l_alpha)
{
    double gamma_pdf = pdf->gamma();
    std::pair<double, double> sampleXYpdf = pdf->createSampler()->randomSample();

    double offset_x_pdf = sampleXYpdf.first;
    double offset_y_pdf = sampleXYpdf.second;

    double x = lattice_positions[index_prev][0] + l * std::cos(l_xi + l_alpha)
               + offset_x_pdf * std::cos(gamma_pdf + l_xi)
               + offset_y_pdf * std::cos(M_PI_2 + gamma_pdf + l_xi); // x coordinate
    double y = lattice_positions[index_prev][1] + l * std::sin(l_xi + l_alpha)
               + offset_x_pdf * std::sin(gamma_pdf + l_xi)
               + offset_y_pdf * std::sin(M_PI_2 + gamma_pdf + l_xi); // y coordinate

    return std::make_pair(x, y);
}

std::pair<double, double> computePositionAlongNegativeLatticeVector(
    const size_t index_prev, std::vector<std::vector<double>>& lattice_positions,
    const IFTDistribution2D* pdf, double l, double l_xi, double l_alpha)
{
    double gamma_pdf = pdf->gamma();
    std::pair<double, double> sampleXYpdf = pdf->createSampler()->randomSample();

    double offset_x_pdf = sampleXYpdf.first;
    double offset_y_pdf = sampleXYpdf.second;

    double x = lattice_positions[index_prev][0] - l * std::cos(l_xi + l_alpha)
               + offset_x_pdf * std::cos(gamma_pdf + l_xi)
               + offset_y_pdf * std::cos(M_PI_2 + gamma_pdf + l_xi); // x coordinate
    double y = lattice_positions[index_prev][1] - l * std::sin(l_xi + l_alpha)
               + offset_x_pdf * std::sin(gamma_pdf + l_xi)
               + offset_y_pdf * std::sin(M_PI_2 + gamma_pdf + l_xi); // y coordinate

    return std::make_pair(x, y);
}

std::pair<double, double>
computeLatticePosition(const size_t index_prev, int i, int j,
                       std::vector<std::vector<double>>& lattice_positions,
                       const IFTDistribution2D* pdf, double l, double l_xi, double l_alpha)
{
    if (std::sin(l_alpha) == 0) {
        if (!(j % 2 == 0)) // along +l1
            return computePositionAlongPositiveLatticeVector(index_prev, lattice_positions, pdf, l,
                                                             l_xi, 0);
        else // along -l1
            return computePositionAlongNegativeLatticeVector(index_prev, lattice_positions, pdf, l,
                                                             l_xi, 0);
    } else {
        if (!(i % 2 == 0)) // along +l2
            return computePositionAlongPositiveLatticeVector(index_prev, lattice_positions, pdf, l,
                                                             l_xi, l_alpha);
        else // along -l2
            return computePositionAlongNegativeLatticeVector(index_prev, lattice_positions, pdf, l,
                                                             l_xi, l_alpha);
    }
}

void computePositionsAlongLatticeVectorAxes(std::vector<std::vector<double>>& lattice_positions,
                                            const IFTDistribution2D* pdf, double l, double l_xi,
                                            double l_alpha)
{
    int n = static_cast<int>((std::sqrt(lattice_positions.size()) - 1) / 2);

    size_t index = 0;      // lattice_positions index for current particle
    size_t index_prev = 0; // lattice_positions index for previous particle

    std::pair<double, double> xy;

    for (int iter = 1; iter <= 2 * n; ++iter) {

        int iterl1, iterl2;

        if (std::sin(l_alpha) == 0) {
            iterl1 = iter;
            iterl2 = 0;
        } else {
            iterl1 = 0;
            iterl2 = iter;
        }

        // The 2*n+1 particles that are situated ONLY along the l1 axis (both +/- axes)
        // are stored in i = 1,2,3,...2*n1 indices of lattice_positions

        // The 2*n+1 particles that are situated ONLY along the l2 axis (both +/- axes)
        // are stored every i*(2*n1+1) index of lattice_positions

        findLatticePositionsIndex(index, index_prev, iterl2, iterl1, n, l_alpha);
        xy = computeLatticePosition(index_prev, iterl2, iterl1, lattice_positions, pdf, l, l_xi,
                                    l_alpha);

        lattice_positions[index][0] = xy.first;  // x coordinate
        lattice_positions[index][1] = xy.second; // y coordinate
    }
}

void computePositionsInsideLatticeQuadrants(std::vector<std::vector<double>>& lattice_positions,
                                            const IFTDistribution2D* pdf1,
                                            const IFTDistribution2D* pdf2, double l1, double l2,
                                            double l_xi, double l_alpha)
{
    int n = static_cast<int>((std::sqrt(lattice_positions.size()) - 1) / 2);

    size_t index = 0;      // lattice_positions index for current particle
    size_t index_prev = 0; // lattice_positions index for previous particle

    std::pair<double, double> xy_l1, xy_l2;

    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; j <= 2 * n; ++j) {
            findLatticePositionsIndex(index, index_prev, i, j, n, 0);
            xy_l1 = computeLatticePosition(index_prev, i, j, lattice_positions, pdf1, l1, l_xi, 0);

            findLatticePositionsIndex(index, index_prev, i, j, n, l_alpha);
            xy_l2 = computeLatticePosition(index_prev, i, j, lattice_positions, pdf2, l2, l_xi,
                                           l_alpha);

            lattice_positions[index][0] = (xy_l1.first + xy_l2.first) / 2;
            lattice_positions[index][1] = (xy_l1.second + xy_l2.second) / 2;
        }
    }
}
}

RealSpace2DParacrystalUtils::RealSpace2DParacrystalUtils()
    : m_interference2DParacrystal(nullptr), m_sceneGeometry(nullptr)
{
}

RealSpace2DParacrystalUtils::~RealSpace2DParacrystalUtils()
{
}

RealSpace2DParacrystalUtils::RealSpace2DParacrystalUtils(
    const InterferenceFunction2DParaCrystal* interference2DParacrystal,
    const SceneGeometry* sceneGeometry)
{
    m_interference2DParacrystal = interference2DParacrystal;
    m_sceneGeometry = sceneGeometry;
}

std::vector<std::vector<double>> RealSpace2DParacrystalUtils::compute2DParacrystalLatticePositions()
{
    double l1 = m_interference2DParacrystal->lattice().length1(); // 1st lattice vector length
    double l2 = m_interference2DParacrystal->lattice().length2(); // 2nd lattice vector length
    double l_alpha = m_interference2DParacrystal->lattice().latticeAngle(); // angle between l1, l2
    double l_xi
        = m_interference2DParacrystal->lattice().rotationAngle(); // angle between l1, x axis
    double layer_size = m_sceneGeometry->layer_size();

    std::vector<std::vector<double>> lattice_positions;
    resizeLatticePositions(lattice_positions, l1, l2, layer_size);

    computePositionsAlongLatticeVectorAxes(lattice_positions, m_interference2DParacrystal->pdf1(),
                                           l1, l_xi, 0);

    computePositionsAlongLatticeVectorAxes(lattice_positions, m_interference2DParacrystal->pdf2(),
                                           l2, l_xi, l_alpha);

    computePositionsInsideLatticeQuadrants(lattice_positions, m_interference2DParacrystal->pdf1(),
                                           m_interference2DParacrystal->pdf2(), l1, l2, l_xi,
                                           l_alpha);

    return lattice_positions;
}
