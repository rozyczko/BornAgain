// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Aggregate/InterferenceFunction3DLattice.cpp
//! @brief     Implements class InterferenceFunction3DLattice.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "InterferenceFunction3DLattice.h"
#include "BornAgainNamespace.h"
#include "Exceptions.h"
#include "IPeakShape.h"
#include <algorithm>

InterferenceFunction3DLattice::InterferenceFunction3DLattice(const Lattice& lattice)
    : m_lattice(lattice)
    , mP_peak_shape(nullptr)
    , m_rec_radius(0.0)
    , m_dw_length(0.0)
{
    initRecRadius();
}

InterferenceFunction3DLattice::~InterferenceFunction3DLattice() =default;


InterferenceFunction3DLattice* InterferenceFunction3DLattice::clone() const
{
    auto P_clone = std::make_unique<InterferenceFunction3DLattice>(m_lattice);
    if (mP_peak_shape)
        P_clone->setPeakShape(*mP_peak_shape);
    P_clone->setDebyeWallerFactor(m_dw_length);
    return P_clone.release();
}

void InterferenceFunction3DLattice::setPeakShape(const IPeakShape& peak_shape)
{
    mP_peak_shape.reset(peak_shape.clone());
}

void InterferenceFunction3DLattice::setDebyeWallerFactor(double dw_length)
{
    m_dw_length = dw_length;
}

double InterferenceFunction3DLattice::evaluate(const kvector_t q) const
{
    if (!mP_peak_shape)
        throw std::runtime_error("InterferenceFunction3DLattice::evaluate: "
                                 "no peak shape defined");
    kvector_t center = q;
    double radius = 2.1 * m_rec_radius;
    double inner_radius = 0.0;
    if (mP_peak_shape->angularDisorder()) {
        center = kvector_t(0.0, 0.0, 0.0);
        inner_radius = std::max(0.0, q.mag()-radius);
        radius += q.mag();
    }
    auto rec_vectors = m_lattice.reciprocalLatticeVectorsWithinRadius(center, radius);
    double result = 0.0;
    for (const auto& q_rec : rec_vectors) {
        if (!(q_rec.mag()<inner_radius)) {
            double dw_factor = std::exp(-q_rec.mag2()*m_dw_length*m_dw_length/3.0);
            result += mP_peak_shape->evaluate(q, q_rec)*dw_factor;
        }
    }
    return result;
}

const Lattice&InterferenceFunction3DLattice::lattice() const
{
    return m_lattice;
}

std::vector<const INode*> InterferenceFunction3DLattice::getChildren() const
{
    return {};
}

void InterferenceFunction3DLattice::onChange()
{
    initRecRadius();
}

void InterferenceFunction3DLattice::initRecRadius()
{
    kvector_t a1 = m_lattice.getBasisVectorA();
    kvector_t a2 = m_lattice.getBasisVectorB();
    kvector_t a3 = m_lattice.getBasisVectorC();

    m_rec_radius = std::max(M_PI / a1.mag(), M_PI / a2.mag());
    m_rec_radius = std::max(m_rec_radius, M_PI / a3.mag());
}
