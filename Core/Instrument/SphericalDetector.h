// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Instrument/SphericalDetector.h
//! @brief     Defines class SphericalDetector.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef SPHERICALDETECTOR_H
#define SPHERICALDETECTOR_H

#include "IDetector2D.h"
#include "IPixel.h"

//! A spherical detector with axes and resolution function.
//! SphericalDetector
//! @ingroup simulation

class BA_CORE_API_ SphericalDetector : public IDetector2D
{
public:
    SphericalDetector();

    //! Spherical detector constructor using angle ranges
    //! @param n_phi number of phi-axis bins
    //! @param phi_min low edge of first phi-bin
    //! @param phi_max upper edge of last phi-bin
    //! @param n_alpha number of alpha-axis bins
    //! @param alpha_min low edge of first alpha-bin
    //! @param alpha_max upper edge of last alpha-bin
    SphericalDetector(size_t n_phi, double phi_min, double phi_max,
                      size_t n_alpha, double alpha_min, double alpha_max);

    SphericalDetector(const SphericalDetector &other);

    SphericalDetector* clone() const override;

    void accept(INodeVisitor* visitor) const override { visitor->visit(this); }

    ~SphericalDetector() override {}

    //! return default axes units
    AxesUnits defaultAxesUnits() const override;

protected:
    //! Create an IPixel for the given OutputData object and index
    IPixel* createPixel(size_t index) const override;

    //! Returns the name for the axis with given index
    std::string axisName(size_t index) const override;

    //! Returns index of pixel that contains the specular wavevector.
    //! If no pixel contains this specular wavevector, the number of pixels is
    //! returned. This corresponds to an overflow index.
    size_t getIndexOfSpecular(const Beam& beam) const override;
};

class SphericalPixel : public IPixel
{
public:
    SphericalPixel(Bin1D alpha_bin, Bin1D phi_bin);
    virtual ~SphericalPixel() {}

    SphericalPixel* clone() const override;
    SphericalPixel* createZeroSizePixel(double x, double y) const override;
    kvector_t getK(double x, double y, double wavelength) const override;
    double getIntegrationFactor(double x, double y) const override;
    double getSolidAngle() const override;
private:
    double m_alpha, m_phi;
    double m_dalpha, m_dphi;
    double m_solid_angle;
};

#endif // SPHERICALDETECTOR_H
