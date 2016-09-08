// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Minimizer/GSLLevenbergMarquardtMinimizer.cpp
//! @brief     Implements class GSLLevenbergMarquardtMinimizer.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "GSLLevenbergMarquardtMinimizer.h"
#include "GSLMultiMinimizer.h"
#include "MinimizerResultsHelper.h"
#include "MinimizerUtils.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include "Math/PatchedGSLNLSMinimizer.h"
#pragma GCC diagnostic pop

namespace {

std::map<int, std::string> covmatrixStatusDescription()
{
    std::map<int, std::string> result;
    result[0] = std::string("Covariance matrix was not computed");
    result[1] = std::string("Covariance matrix approximate because minimum is not valid");
    result[3] = std::string("Covariance matrix OK");
    return result;
}

}

GSLLevenbergMarquardtMinimizer::GSLLevenbergMarquardtMinimizer()
    : BasicMinimizer(MinimizerInfo::buildGSLLMAInfo())
    , m_gsl_minimizer(new BA_ROOT::Math::GSLNLSMinimizer(2))
{
    addOption(OptionNames::Tolerance, 0.01, "Tolerance on the function value at the minimum");
    addOption(OptionNames::PrintLevel, 0, "Minimizer internal print level");
    addOption(OptionNames::MaxIterations, 0, "Maximum number of iterations");
}

GSLLevenbergMarquardtMinimizer::~GSLLevenbergMarquardtMinimizer()
{

}

void GSLLevenbergMarquardtMinimizer::setTolerance(double value)
{
    setOptionValue(OptionNames::Tolerance, value);
}

double GSLLevenbergMarquardtMinimizer::tolerance() const
{
    return optionValue<double>(OptionNames::Tolerance);
}

void GSLLevenbergMarquardtMinimizer::setPrintLevel(int value)
{
    setOptionValue(OptionNames::PrintLevel, value);
}

int GSLLevenbergMarquardtMinimizer::printLevel() const
{
    return optionValue<int>(OptionNames::PrintLevel);
}

void GSLLevenbergMarquardtMinimizer::setMaxIterations(int value)
{
    setOptionValue(OptionNames::MaxIterations, value);
}

int GSLLevenbergMarquardtMinimizer::maxIterations() const
{
    return optionValue<int>(OptionNames::MaxIterations);
}

std::string GSLLevenbergMarquardtMinimizer::statusToString() const
{
    return MinimizerUtils::gslErrorDescription(rootMinimizer()->Status());
}

std::map<std::string, std::string> GSLLevenbergMarquardtMinimizer::statusMap() const
{
    auto result = BasicMinimizer::statusMap();
    result["Edm"] = to_string_scientific(rootMinimizer()->Edm());
    result["CovMatrixStatus"] = covmatrixStatusDescription()[rootMinimizer()->CovMatrixStatus()];
    result["functionCalls"] = std::to_string(rootMinimizer()->NCalls());
    return result;
}

void GSLLevenbergMarquardtMinimizer::propagateOptions()
{
    m_gsl_minimizer->SetTolerance(tolerance());
    m_gsl_minimizer->SetPrintLevel(printLevel());
    m_gsl_minimizer->SetMaxIterations(maxIterations());
}

const BasicMinimizer::root_minimizer_t *GSLLevenbergMarquardtMinimizer::rootMinimizer() const
{
    return m_gsl_minimizer.get();
}
