#ifndef TESTPYGENERATOR_H
#define TESTPYGENERATOR_H
#include "IApplicationTest.h"
#include "PyGenVisitor.h"

class MultiLayer;

class TestPyGenerator : public IApplicationTest
{
public:
    TestPyGenerator();
    virtual ~TestPyGenerator(){}
    virtual void execute();

private:
    PyGenVisitor visitor;
    Simulation *makeSimulation();
    MultiLayer *makeSample();
    Simulation *m_simulation;
    MultiLayer *m_sample;


};

#endif //

