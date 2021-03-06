// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Instrument/UnitConverterUtils.cpp
//! @brief     Implements utilities for unit convertion.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "UnitConverterUtils.h"
#include "Instrument.h"
#include "OutputData.h"
#include "RectangularDetector.h"
#include "SimpleUnitConverters.h"
#include "SphericalDetector.h"
#include "UnitConverter1D.h"
#include "GISASSimulation.h"
#include "OffSpecSimulation.h"
#include "SpecularSimulation.h"
#include "DepthProbeSimulation.h"

std::unique_ptr<OutputData<double>>
UnitConverterUtils::createOutputData(const IUnitConverter& converter, AxesUnits units)
{
    std::unique_ptr<OutputData<double>> result = std::make_unique<OutputData<double>>();
    for (size_t i = 0; i < converter.dimension(); ++i)
        result->addAxis(*converter.createConvertedAxis(i, units));
    result->setAllTo(0.0);
    return result;
}

std::unique_ptr<IUnitConverter>
UnitConverterUtils::createConverterForGISAS(const Instrument& instrument)
{
    const auto detector = instrument.getDetector();

    if (const auto spher_detector = dynamic_cast<const SphericalDetector*>(detector))
        return std::make_unique<SphericalConverter>(*spher_detector, instrument.getBeam());
    else if (const auto rect_detector = dynamic_cast<const RectangularDetector*>(detector))
        return std::make_unique<RectangularConverter>(*rect_detector, instrument.getBeam());

    throw std::runtime_error(
        "Error in createConverterForGISAS: wrong or absent detector type");
}

std::unique_ptr<IUnitConverter> UnitConverterUtils::createConverter(const Simulation& simulation)
{
    if(auto gisas = dynamic_cast<const GISASSimulation*>(&simulation)) {
        return createConverterForGISAS(gisas->getInstrument());

    } else if (auto spec = dynamic_cast<const SpecularSimulation*>(&simulation)) {
        return std::make_unique<UnitConverter1D>(spec->getInstrument().getBeam(),
                                                 *spec->getAlphaAxis());

    } else if (auto probe = dynamic_cast<const DepthProbeSimulation*>(&simulation)) {
        return probe->createUnitConverter();

    } else {
        throw std::runtime_error("UnitConverterUtils::createConverter -> "
                                 "Not implemented simulation.");
    }
}
