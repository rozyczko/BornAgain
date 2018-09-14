// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Tests/Functional/Fit/FitObjective/FitObjectiveTestCases.h
//! @brief     Defines classes from FitObjectiveTest family.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef FITOBJECTIVETESTCASES_H
#define FITOBJECTIVETESTCASES_H

//! Collection of FitObjective tests.

#include "FitObjectiveTest.h"

class MigradCylindersInBA : public FitObjectiveTest
{
public:
    MigradCylindersInBA();
};

class BfgsCylindersInBA : public FitObjectiveTest
{
public:
    BfgsCylindersInBA();
};

class SteepestDescentCylindersInBA : public FitObjectiveTest
{
public:
    SteepestDescentCylindersInBA();
};

class FumuliCylindersInBA : public FitObjectiveTest
{
public:
    FumuliCylindersInBA();
};

class LevenbergMarquardtCylindersInBA : public FitObjectiveTest
{
public:
    LevenbergMarquardtCylindersInBA();
};

class SimAnCylindersInBA : public FitObjectiveTest
{
public:
    SimAnCylindersInBA();
};

class GeneticCylindersInBA : public FitObjectiveTest
{
public:
    GeneticCylindersInBA();
};

class RectDetectorFit : public FitObjectiveTest
{
public:
    RectDetectorFit();
};

class AdjustMinimizerFit : public FitObjectiveTest
{
public:
    AdjustMinimizerFit();
};

//! FIXME Reproduces conditions of FitSuite/MultiPatternFitTest. After cleanup of FitSuite, given
//! test can be also removed, since it doesn't demonstrate/check any new fit machinery.
class MultiPatternFit : public FitObjectiveTest
{
public:
    MultiPatternFit();

};

class SpecularFitTest : public FitObjectiveTest
{
public:
    SpecularFitTest();
};

class MultipleSpecFittingTest : public FitObjectiveTest
{
public:
    MultipleSpecFittingTest();
};

#endif //   MINIMIZERTESTCASES_H