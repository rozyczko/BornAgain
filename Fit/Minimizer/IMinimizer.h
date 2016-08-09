// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Minimizer/IMinimizer.h
//! @brief     Defines class IMinimizer.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef IMINIMIZER_H
#define IMINIMIZER_H

#include "WinDllMacros.h"
#include <functional>
#include <vector>

class FitParameter;
class FitSuiteParameters;
class MinimizerOptions;

//! @class IMinimizer
//! @ingroup fitting_internal
//! @brief Common interface for all kind minimizer's

class BA_CORE_API_ IMinimizer
{
 public:
    //! signature of chi squared function to minimize
    typedef std::function<double(const double*)> function_chi2_t;

    //! signature of gradient to minimize with access to single data element residuals
    typedef std::function<double(const double*, unsigned int, double*)> function_gradient_t;

    IMinimizer() { }
    virtual ~IMinimizer() { }

    //! run minimization
    virtual void minimize();

    //! Sets internal minimizer parameter
    virtual void setParameter(size_t index, const FitParameter* par);

    //! Sets internal minimizer parameters using external parameter list
    virtual void setParameters(const FitSuiteParameters& parameters);

    //! Sets chi squared function to minimize
    virtual void setChiSquaredFunction(function_chi2_t fun_chi2, size_t nparameters);

    //! Sets gradient function to minimize
    virtual void setGradientFunction(
        function_gradient_t fun_gradient, size_t nparameters, size_t ndatasize);

    //! Returns number of variables to fit
    virtual size_t getNumberOfVariables() const;

    //! Returns minimum function value
    virtual double getMinValue() const;

    //! Returns value of the parameter at the minimum
    virtual double getValueOfVariableAtMinimum(size_t index) const;

    //! Returns values of parameters at the minimum
    virtual std::vector<double > getValueOfVariablesAtMinimum() const;

    //! Returns error of variable at minimum
    virtual double getErrorOfVariable(size_t index) const;

    //! Returns errors of variables at minimum
    virtual std::vector<double >  getErrorOfVariables() const;

    //! clear resources (parameters) for consecutives minimizations
    virtual void clear();

    //! Prints fit results
    virtual void printResults() const;

    //! Returns number of calls of minimized function
    virtual size_t getNCalls() const;

    //! return minimizer options
    virtual MinimizerOptions* getOptions();
    virtual const MinimizerOptions* getOptions() const;

    //! set minimizer options
    virtual void setOptions(const MinimizerOptions& options);

    //! set minimizer option string
    virtual void setOptionString(const std::string& options);

    //! Returns true if type of algorithm is Levenberg-Marquardt or similar
    virtual bool isGradientBasedAgorithm();

    //! return name of the minimizer
    virtual std::string getMinimizerName() const;

    //! return name of the minimization algorithm
    virtual std::string getAlgorithmName() const;
};

#endif // IMINIMIZER_H