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
#include "ISelectionRule.pypp.h"

namespace bp = boost::python;

struct ISelectionRule_wrapper : ISelectionRule, bp::wrapper< ISelectionRule > {

    ISelectionRule_wrapper()
    : ISelectionRule()
      , bp::wrapper< ISelectionRule >(){
        // null constructor
        
    }

    virtual ::ISelectionRule * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual bool coordinateSelected( ::Coordinate3D< int > const & coordinate ) const {
        bp::override func_coordinateSelected = this->get_override( "coordinateSelected" );
        return func_coordinateSelected( boost::ref(coordinate) );
    }

};

void register_ISelectionRule_class(){

    bp::class_< ISelectionRule_wrapper, boost::noncopyable >( "ISelectionRule" )    
        .def( 
            "clone"
            , bp::pure_virtual( (::ISelectionRule * ( ::ISelectionRule::* )(  ) const)(&::ISelectionRule::clone) )
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "coordinateSelected"
            , bp::pure_virtual( (bool ( ::ISelectionRule::* )( ::Coordinate3D< int > const & ) const)(&::ISelectionRule::coordinateSelected) )
            , ( bp::arg("coordinate") ) );

}
