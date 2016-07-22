// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/TestMachinery/IStandardTest.h
//! @brief     Declares class IStandardTest.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FUNCTIONALTESTSUITE_H
#define FUNCTIONALTESTSUITE_H

#include "INamed.h" // inheriting from

class GISASSimulation;
class IFunctionalTest;
class FunctionalTestInfo;
class IParameterized;

//! @class IStandardTest
//! @brief Base class for Core/PyCore/GUI tests that involve standard simulations.

//! For Foo in {Core, PyCore, GUI}, the functional test mechanism is as follows:
//!
//! FooTestSuite is the executable obtained from
//!   main(argv,argc) in FooTestSuite.cpp,
//! which runs
//!   FooTestSuite().execute(argv,argc),
//! which is inherited from here. This function,
//!   IStandardTest::execute(argv,argc)
//! uses argv[1] to retrieve a set of parameters from FunctionalTestRegistry.
//! Then it bifurcates into
//!   IStandardTest::execute_onetest(argv,argc) or
//!   IStandardTest::execute_subtests(argv,argc)
//! which will call
//!   IFunctionalTest::getTest(),
//! which is the only nontrivial member of FooTestSuite, implemented in FooTestSuite.cpp.
//! The return value
//!   test = new FooTest( <parameters> )
//! is provided by FooTest.cpp.
//! The arguments in this constructor are callback functions provided by IStandardTest;
//! they contain information gathered from FunctionalTestRegistry, and possibly from
//! a subtest registry.
//! Finally, IStandardTest::execute_... will call
//!   test->runTest()        // implemented in FooTest
//!   test->analyseResults() // implemented in FooTest
//!   test->getTestResult()  // implemented in IFunctionalTest

class BA_CORE_API_ IStandardTest : public INamed
{
public:
    IStandardTest(const std::string& name) : INamed(name) {}
    virtual ~IStandardTest() {}

    int execute(int argc, char** argv);

    virtual IFunctionalTest* getTest() const = 0; //!< overloaded in (Core|Py|GUI)Suite.cpp

protected:
    virtual GISASSimulation* getSimulation() const;
    std::string getTestName() const { return m_test_name; }
    std::string getTestDescription() const;
    double getTestThreshold() const;

private:
    const FunctionalTestInfo* m_info;
    std::string m_test_name;
    const IParameterized* m_subtest_item;

    int execute_onetest();
    int execute_subtests();
};

#endif // FUNCTIONALTESTSUITE_H
