// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/HardParticle/FormFactorFullSphere.h
//! @brief     Defines class FormFactorFullSphere.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORFULLSPHERE_H
#define FORMFACTORFULLSPHERE_H

#include "IFormFactorBorn.h"

//! @ingroup formfactors
//! @class FormFactorFullSphere
//! @brief The formfactor of a sphere.
class BA_CORE_API_ FormFactorFullSphere : public IFormFactorBorn
{
public:
    //! @brief Full Sphere constructor
    //! @param radius of Sphere
    FormFactorFullSphere(double radius);

    FormFactorFullSphere *clone() const{ return new FormFactorFullSphere(m_radius); }
    void accept(ISampleVisitor *visitor) const final { visitor->visit(this); }

    double getRadius() const { return m_radius; }

    double getRadialExtension() const final { return m_radius; }

    complex_t evaluate_for_q(const cvector_t q) const final;

private:
    double m_radius;
};

#endif // FORMFACTORFULLSPHERE_H