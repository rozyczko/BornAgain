// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/inc/FormFactorEllipsoidalCylinder.h
//! @brief     Defines class FormFactorEllipsoidalCylinder
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORELLIPSOIDALCYLINDER_H
#define FORMFACTORELLIPSOIDALCYLINDER_H

#include "IFormFactorBorn.h"
#include "IStochasticParameter.h"

//! Form factor of an ellipsoidal cylinder.

class BA_CORE_API_ FormFactorEllipsoidalCylinder : public IFormFactorBorn
{
public:
    FormFactorEllipsoidalCylinder(double radius, double width,
                        double height);
    ~FormFactorEllipsoidalCylinder() {}
    virtual FormFactorEllipsoidalCylinder *clone() const;

    virtual void accept(ISampleVisitor *visitor) const { visitor->visit(this); }

    virtual int getNumberOfStochasticParameters() const { return 3; }

    double getRadius() const { return m_radius; }
    virtual void setRadius(double radius) { m_radius = radius; }

    virtual double getWidth() const { return m_width; }
    virtual void setWidth(double width) { m_width = width; }

    virtual double getHeight() const { return m_height; }
    virtual void setHeight(double height) { m_height = height; }

    virtual complex_t evaluate_for_q(const cvector_t& q) const;

protected:

    //! Registers some class members for later access via parameter pool
    virtual void init_parameters();

private:
    double m_radius;
    double m_width;
    double m_height;

};

#endif // FORMFACTORELLIPSOIDALCYLINDER_H

