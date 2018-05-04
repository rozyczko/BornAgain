// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/NewKernel/ScalarFunctionAdapter.h
//! @brief     Defines class ScalarFunctionAdapter.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "ScalarFunctionAdapter.h"
#include "KernelTypes.h"
#include "RootMinimizerFunctions.h"

using namespace Fit;

ScalarFunctionAdapter::ScalarFunctionAdapter(fcn_scalar_t func, const Parameters& parameters)
    : m_fcn(func), m_parameters(parameters)
{
}

const RootObjectiveFunction* ScalarFunctionAdapter::rootObjectiveFunction()
{
    root_objective_t rootfun = [&](const double* pars) {
        std::vector<double> vec;
        vec.resize(m_parameters.size(), 0.0);
        std::copy(pars, pars + m_parameters.size(), vec.begin());
        ++m_number_of_calls;
        return m_fcn(vec);
    };

    m_root_objective.reset(
        new RootObjectiveFunction(rootfun, static_cast<int>(m_parameters.size())));
    return m_root_objective.get();
}