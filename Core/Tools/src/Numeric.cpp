// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tools/inc/Numeric.cpp
//! @brief     Implements "almost equal" in namespace Numeric.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Numeric.h"

//! Floating-point epsilon, tolerances, almost-equal.

namespace Numeric {

//! compare two doubles
bool areAlmostEqual(double a, double b, double tolerance_factor)
    { return get_relative_difference(a, b) < tolerance_factor*double_epsilon; }


//! calculates safe relative difference |(a-b)/b|
double get_relative_difference(double a, double b)
{
    // return 0.0 if relative error smaller than epsilon
    if (std::abs(a-b) <= double_epsilon*std::abs(b)) return 0.0;
    // for small numbers, divide by epsilon (to avoid catastrophic cancellation)
    if (std::abs(b) <= double_epsilon) return std::abs((a-b)/double_epsilon);
    return std::abs((a-b)/b);
}

} // Numeric namespace
