// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/GUI/GUIStandardTest/GUIStandardTest.cpp
//! @brief     Implements class GUIStandardTest
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "GUIStandardTest.h"
#include "DocumentModel.h"
#include "DomainSimulationBuilder.h"
#include "Simulation.h"
#include "GUIObjectBuilder.h"
#include "InstrumentModel.h"
#include "MaterialModel.h"
#include "SampleModel.h"
#include "InstrumentItems.h"
#include "TestUtils.h"

namespace
{
std::unique_ptr<Simulation> createDomainSimulation(const Simulation& origin)
{
    // initializing necessary GUI
    const std::unique_ptr<DocumentModel> documentModel(new DocumentModel);
    const std::unique_ptr<SampleModel> sampleModel(new SampleModel);
    const std::unique_ptr<InstrumentModel> instrumentModel(new InstrumentModel);
    const std::unique_ptr<MaterialModel> materialModel(new MaterialModel);

    // populating GUI models from domain
    GUIObjectBuilder::populateSampleModelFromSim(sampleModel.get(), materialModel.get(), origin);
    GUIObjectBuilder::populateInstrumentModel(instrumentModel.get(), origin);
    GUIObjectBuilder::populateDocumentModel(documentModel.get(), origin);

    auto result = DomainSimulationBuilder::createSimulation(sampleModel->multiLayerItem(),
            instrumentModel->instrumentItem(), documentModel->simulationOptionsItem());

    return result;
}
}

bool GUIStandardTest::runTest()
{
    m_reference_simulation->runSimulation();
    auto ref_result = m_reference_simulation->result();

    auto domain_simulation = createDomainSimulation(*m_reference_simulation);
    domain_simulation->runSimulation();
    auto domain_result = domain_simulation->result();

    const std::unique_ptr<OutputData<double> > domain_data(domain_result.data());
    const std::unique_ptr<OutputData<double> > reference_data(ref_result.data());

    return TestUtils::isTheSame(*domain_data, *reference_data, m_threshold);
}
