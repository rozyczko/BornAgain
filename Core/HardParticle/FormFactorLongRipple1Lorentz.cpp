// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/HardParticle/FormFactorLongRipple1Lorentz.cpp
//! @brief     Implements class FormFactorLongRipple1Lorentz.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "FormFactorLongRipple1Lorentz.h"
#include "BornAgainNamespace.h"
#include "Box.h"
#include "Exceptions.h"
#include "MathFunctions.h"
#include "MathConstants.h"
#include "RealParameter.h"

FormFactorLongRipple1Lorentz::FormFactorLongRipple1Lorentz(
    double length, double width, double height)
    : m_length(length), m_width(width), m_height(height)
{
    setName(BornAgain::FFLongRipple1LorentzType);
    check_initialization();
    registerParameter(BornAgain::Length, &m_length).setUnit(BornAgain::UnitsNm).setNonnegative();
    registerParameter(BornAgain::Width, &m_width).setUnit(BornAgain::UnitsNm).setNonnegative();
    registerParameter(BornAgain::Height, &m_height).setUnit(BornAgain::UnitsNm).setNonnegative();
    mP_integrator = make_integrator_complex(this, &FormFactorLongRipple1Lorentz::Integrand);
    onChange();
}

bool FormFactorLongRipple1Lorentz::check_initialization() const
{
    bool result(true);
    if(m_height <=0.0 || m_width<=0.0 || m_length<=0.0) {
        std::ostringstream ostr;
        ostr << "FormFactorLongRipple1Lorentz() -> Error in class initialization with parameters ";
        ostr << " height:" << m_height;
        ostr << " width:" << m_width;
        ostr << " length:" << m_length << "\n\n";
        ostr << "Check for 'height>0.0 && width>0.0 && length>0.0' failed.";
        throw Exceptions::ClassInitializationException(ostr.str());
    }
    return result;
}

double FormFactorLongRipple1Lorentz::radialExtension() const
{
    return ( m_width + m_length ) / 4.0;
}

//! Integrand for complex formfactor.
complex_t FormFactorLongRipple1Lorentz::Integrand(double Z) const
{
    complex_t aa = std::acos(2.0*Z/m_height - 1.0);
    return exp_I(m_q.z()*Z) * aa * MathFunctions::sinc(aa*m_q.y() * m_width/(M_TWOPI));
}

//! Complex formfactor.
complex_t FormFactorLongRipple1Lorentz::evaluate_for_q(cvector_t q) const
{
    m_q = q;

    complex_t qxL2 = 2.5*std::pow(m_length * q.x(), 2);
    complex_t factor = m_length/(1.0 + qxL2)*m_width/M_PI;

    complex_t aaa = q.y()*m_width/(M_TWOPI);
    complex_t aaa2 = aaa*aaa;

    // analytical expressions for some particular cases
    if (0.0==q.y() && 0.0==q.z())
        return factor*M_PI_2*m_height;
    else if (0.0==q.z() && 1.0 == aaa2)
        return factor*M_PI_4*m_height;
    else if (0.0==q.z())
        return factor*M_PI_2*m_height*MathFunctions::sinc(q.y()*m_width*0.5)/(1.0-aaa2);

    // numerical integration otherwise
    complex_t integral = mP_integrator->integrate(0, m_height);
    return factor*integral;
}

void FormFactorLongRipple1Lorentz::onChange()
{
    mP_shape.reset(new Box(m_length, m_width, m_height));
}
