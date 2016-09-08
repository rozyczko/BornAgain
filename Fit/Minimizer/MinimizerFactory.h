// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Minimizer/MinimizerFactory.h
//! @brief     Defines class MinimizerFactory.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef MINIMIZERFACTORY_H
#define MINIMIZERFACTORY_H

#include "WinDllMacros.h"
#include "MinimizerCatalogue.h"
#include <string>
class IMinimizer;

//! @class MinimizerFactory
//! @ingroup fitting
//! @brief Factory to create minimizers

/*!

--------------------------------------------------------------------------------
Minimizer      | Algorithms
--------------------------------------------------------------------------------
Minuit2        | Migrad Simplex Combined Scan Fumili
GSLMultiMin    | SteepestDescent ConjugateFR ConjugatePR BFGS BFGS2
GSLLMA         | Default
GSLSimAn       | Default
Genetic        | Default

*/


class BA_CORE_API_ MinimizerFactory
{
 public:
    static IMinimizer* createMinimizer(
        const std::string& minimizerName,
        const std::string& algorithmType="",
        const std::string& options="" );

    static void printCatalogue();

    static std::string catalogueToString();

    //! Returns copy of minimizer type and settings. No full clone, would be too heavy!
    static IMinimizer* createMinimizer(const IMinimizer* other);

    static const MinimizerCatalogue& catalogue();

private:
    static MinimizerCatalogue m_catalogue;
};

#endif // MINIMIZERFACTORY_H
