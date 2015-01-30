// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FitKernel/inc/FitSuiteStrategies.h
//! @brief     Defines class FitSuiteStrategies.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FITSUITESTRATEGIES_H
#define FITSUITESTRATEGIES_H

#include "SafePointerVector.h"
#include "IFitStrategy.h"

class FitSuite;

//! @class FitSuiteStrategies
//! @ingroup fitting_internal
//! @brief Collection of strategies to fit

class BA_CORE_API_  FitSuiteStrategies
{
 public:
    typedef SafePointerVector<IFitStrategy > strategies_t;
    typedef strategies_t::iterator iterator;

    FitSuiteStrategies();
    virtual ~FitSuiteStrategies();

    void init(FitSuite *fit_suite) { m_fit_suite = fit_suite; }

    void addStrategy(IFitStrategy *strategy);

    void minimize();

    size_t getCurrentStrategyIndex() const { return m_current_strategy_index; }
    std::string getCurrentStrategyName() const { return m_current_strategy_name; }

    iterator begin() { return m_strategies.begin(); }
    iterator end() { return m_strategies.end(); }
    size_t size() const { return m_strategies.size(); }

    void clear();
 private:
    strategies_t m_strategies;
    FitSuite *m_fit_suite;
    size_t m_current_strategy_index;
    std::string m_current_strategy_name;
};

#endif // FITSUITESTRATEGIES_H


