// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Instrument/DetectorFunctions.cpp
//! @brief     Implements namespace DetectorFunctions.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "DetectorFunctions.h"
#include "OutputData.h"
#include "Instrument.h"
#include "SimulationArea.h"
#include "SimulationAreaIterator.h"
#include "StringUtils.h"
#include <sstream>
#include <algorithm>
#include <map>
#include <cctype>

bool DetectorFunctions::hasSameDimensions(const IDetector& detector, const OutputData<double>& data)
{
    if (data.getRank() != detector.dimension())
        return false;

    for (size_t i = 0; i < detector.dimension(); ++i)
        if(data.getAxis(i).size() != detector.getAxis(i).size())
            return false;

    return true;
}

std::string DetectorFunctions::axesToString(const IDetector& detector)
{
    std::ostringstream result;

    result << "(";
    for (size_t i = 0; i < detector.dimension(); ++i) {
        result << detector.getAxis(i).size();
        if(i!=detector.dimension()-1)
            result << ",";
    }
    result << ")";

    return result.str();
}

std::string DetectorFunctions::axesToString(const OutputData<double> &data)
{
    std::ostringstream result;

    result << "(";
    for (size_t i = 0; i < data.getRank(); ++i) {
        result << data.getAxis(i).size();
        if(i!=data.getRank()-1)
            result << ",";
    }
    result << ")";

    return result.str();
}
