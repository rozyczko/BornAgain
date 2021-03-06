// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Core/CoreSpecial/BatchSimulation.h
//! @brief     Defines BatchSimulation class.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BATCHSIMULATION_H
#define BATCHSIMULATION_H

#include "IFunctionalTest.h"

//! Special test for simulation running in batch mode.

class BatchSimulation : public IFunctionalTest {
protected:
    bool runTest();
};

#endif

