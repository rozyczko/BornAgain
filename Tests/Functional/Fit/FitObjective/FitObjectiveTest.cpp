// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Fit/FitObjective/FitObjectiveTest.h
//! @brief     Defines class FitObjectiveTest
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "FitObjectiveTest.h"
#include "FitPlanFactory.h"

FitObjectiveTest::FitObjectiveTest(const std::string& minimizer_name,
                                   const std::string& algorithm_name,
                                   const std::string& fit_plan_name)
    : IMinimizerTest(minimizer_name, algorithm_name, fit_plan_name)
{
}

std::unique_ptr<MinimizerTestPlan> FitObjectiveTest::createPlan() const
{
    FitPlanFactory factory;
    return factory.create(m_fit_plan_name);
}
