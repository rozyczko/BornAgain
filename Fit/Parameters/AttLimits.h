// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Parameters/AttLimits.h
//! @brief     Defines and implements class AttLimits.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef ATTLIMITS_H
#define ATTLIMITS_H

#include "WinDllMacros.h"
#include "RealLimits.h"
#include "Attributes.h"

//! @class AttLimits
//! @ingroup fitting
//! @brief The AttLimits class defines limited/free attribute of fit parameter.

class BA_CORE_API_ AttLimits
{
public:
    AttLimits();
    AttLimits(const RealLimits &limits, const Attributes &fixedAttr); // TODO make private

    static AttLimits limitless();
    static AttLimits lowerLimited(double bound_value);
    static AttLimits positive();
    static AttLimits nonnegative();
    static AttLimits upperLimited(double bound_value);
    static AttLimits limited(double left_bound_value, double right_bound_value);
    static AttLimits fixed();

    bool isFixed() const;
    bool isLimited() const;
    bool isUpperLimited() const;
    bool isLowerLimited() const;
    bool isLimitless() const;

    double lowerLimit() const;
    double upperLimit() const;

    void setFixed(bool isFixed);

    bool operator==(const AttLimits &other) const;
    bool operator!=(const AttLimits &other) const { return !(*this == other); }

    std::string toString() const;

private:

    RealLimits m_limits;
    Attributes m_att_fixed;
};


#endif
