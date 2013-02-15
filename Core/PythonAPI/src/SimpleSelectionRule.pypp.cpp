// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "Experiment.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "Experiment.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "InterferenceFunctionNone.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Lattice.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "Particle.h"
#include "Crystal.h"
#include "ParticleDecoration.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "ParticleInfo.h"
#include "DiffuseParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Transform3D.h"
#include "Units.h"
#include "Types.h"
#include "SimpleSelectionRule.pypp.h"

namespace bp = boost::python;

struct SimpleSelectionRule_wrapper : SimpleSelectionRule, bp::wrapper< SimpleSelectionRule > {

    SimpleSelectionRule_wrapper(SimpleSelectionRule const & arg )
    : SimpleSelectionRule( arg )
      , bp::wrapper< SimpleSelectionRule >(){
        // copy constructor
        
    }

    SimpleSelectionRule_wrapper(int a, int b, int c, int modulus )
    : SimpleSelectionRule( a, b, c, modulus )
      , bp::wrapper< SimpleSelectionRule >(){
        // constructor
    
    }

    virtual ::SimpleSelectionRule * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->SimpleSelectionRule::clone(  );
        }
    }
    
    ::SimpleSelectionRule * default_clone(  ) const  {
        return SimpleSelectionRule::clone( );
    }

    virtual bool coordinateSelected( ::Coordinate3D< int > const & coordinate ) const  {
        if( bp::override func_coordinateSelected = this->get_override( "coordinateSelected" ) )
            return func_coordinateSelected( boost::ref(coordinate) );
        else{
            return this->SimpleSelectionRule::coordinateSelected( boost::ref(coordinate) );
        }
    }
    
    bool default_coordinateSelected( ::Coordinate3D< int > const & coordinate ) const  {
        return SimpleSelectionRule::coordinateSelected( boost::ref(coordinate) );
    }

};

void register_SimpleSelectionRule_class(){

    bp::class_< SimpleSelectionRule_wrapper, bp::bases< ISelectionRule > >( "SimpleSelectionRule", bp::init< int, int, int, int >(( bp::arg("a"), bp::arg("b"), bp::arg("c"), bp::arg("modulus") )) )    
        .def( 
            "clone"
            , (::SimpleSelectionRule * ( ::SimpleSelectionRule::* )(  ) const)(&::SimpleSelectionRule::clone)
            , (::SimpleSelectionRule * ( SimpleSelectionRule_wrapper::* )(  ) const)(&SimpleSelectionRule_wrapper::default_clone)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "coordinateSelected"
            , (bool ( ::SimpleSelectionRule::* )( ::Coordinate3D< int > const & ) const)(&::SimpleSelectionRule::coordinateSelected)
            , (bool ( SimpleSelectionRule_wrapper::* )( ::Coordinate3D< int > const & ) const)(&SimpleSelectionRule_wrapper::default_coordinateSelected)
            , ( bp::arg("coordinate") ) );

}
