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
#include "Transform3D.pypp.h"

namespace bp = boost::python;

void register_Transform3D_class(){

    { //::Geometry::Transform3D
        typedef bp::class_< Geometry::Transform3D > Transform3D_exposer_t;
        Transform3D_exposer_t Transform3D_exposer = Transform3D_exposer_t( "Transform3D", bp::init< >() );
        bp::scope Transform3D_scope( Transform3D_exposer );
        bp::class_< Geometry::Transform3D::Transform3D_row, boost::noncopyable >( "Transform3D_row", bp::no_init );
        Transform3D_exposer.def( bp::init< Geometry::Transform3D const & >(( bp::arg("m") )) );
        { //::Geometry::Transform3D::dx
        
            typedef double ( ::Geometry::Transform3D::*dx_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "dx"
                , dx_function_type( &::Geometry::Transform3D::dx ) );
        
        }
        { //::Geometry::Transform3D::dy
        
            typedef double ( ::Geometry::Transform3D::*dy_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "dy"
                , dy_function_type( &::Geometry::Transform3D::dy ) );
        
        }
        { //::Geometry::Transform3D::dz
        
            typedef double ( ::Geometry::Transform3D::*dz_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "dz"
                , dz_function_type( &::Geometry::Transform3D::dz ) );
        
        }
        { //::Geometry::Transform3D::getDecomposition
        
            typedef void ( ::Geometry::Transform3D::*getDecomposition_function_type )( ::Geometry::Scale3D &,::Geometry::Rotate3D &,::Geometry::Translate3D & ) const;
            
            Transform3D_exposer.def( 
                "getDecomposition"
                , getDecomposition_function_type( &::Geometry::Transform3D::getDecomposition )
                , ( bp::arg("scale"), bp::arg("rotation"), bp::arg("translation") ) );
        
        }
        { //::Geometry::Transform3D::inverse
        
            typedef ::Geometry::Transform3D ( ::Geometry::Transform3D::*inverse_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "inverse"
                , inverse_function_type( &::Geometry::Transform3D::inverse ) );
        
        }
        { //::Geometry::Transform3D::isNear
        
            typedef bool ( ::Geometry::Transform3D::*isNear_function_type )( ::Geometry::Transform3D const &,double ) const;
            
            Transform3D_exposer.def( 
                "isNear"
                , isNear_function_type( &::Geometry::Transform3D::isNear )
                , ( bp::arg("t"), bp::arg("tolerance")=2.20000000000000009206578920655319378310295179435041035276e-14 ) );
        
        }
        Transform3D_exposer.def( bp::self != bp::self );
        { //::Geometry::Transform3D::operator()
        
            typedef double ( ::Geometry::Transform3D::*__call___function_type )( int,int ) const;
            
            Transform3D_exposer.def( 
                "__call__"
                , __call___function_type( &::Geometry::Transform3D::operator() )
                , ( bp::arg("arg0"), bp::arg("arg1") ) );
        
        }
        Transform3D_exposer.def( bp::self * bp::self );
        { //::Geometry::Transform3D::operator=
        
            typedef ::Geometry::Transform3D & ( ::Geometry::Transform3D::*assign_function_type )( ::Geometry::Transform3D const & ) ;
            
            Transform3D_exposer.def( 
                "assign"
                , assign_function_type( &::Geometry::Transform3D::operator= )
                , ( bp::arg("m") )
                , bp::return_self< >() );
        
        }
        Transform3D_exposer.def( bp::self == bp::self );
        { //::Geometry::Transform3D::setIdentity
        
            typedef void ( ::Geometry::Transform3D::*setIdentity_function_type )(  ) ;
            
            Transform3D_exposer.def( 
                "setIdentity"
                , setIdentity_function_type( &::Geometry::Transform3D::setIdentity ) );
        
        }
        { //::Geometry::Transform3D::xx
        
            typedef double ( ::Geometry::Transform3D::*xx_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "xx"
                , xx_function_type( &::Geometry::Transform3D::xx ) );
        
        }
        { //::Geometry::Transform3D::xy
        
            typedef double ( ::Geometry::Transform3D::*xy_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "xy"
                , xy_function_type( &::Geometry::Transform3D::xy ) );
        
        }
        { //::Geometry::Transform3D::xz
        
            typedef double ( ::Geometry::Transform3D::*xz_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "xz"
                , xz_function_type( &::Geometry::Transform3D::xz ) );
        
        }
        { //::Geometry::Transform3D::yx
        
            typedef double ( ::Geometry::Transform3D::*yx_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "yx"
                , yx_function_type( &::Geometry::Transform3D::yx ) );
        
        }
        { //::Geometry::Transform3D::yy
        
            typedef double ( ::Geometry::Transform3D::*yy_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "yy"
                , yy_function_type( &::Geometry::Transform3D::yy ) );
        
        }
        { //::Geometry::Transform3D::yz
        
            typedef double ( ::Geometry::Transform3D::*yz_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "yz"
                , yz_function_type( &::Geometry::Transform3D::yz ) );
        
        }
        { //::Geometry::Transform3D::zx
        
            typedef double ( ::Geometry::Transform3D::*zx_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "zx"
                , zx_function_type( &::Geometry::Transform3D::zx ) );
        
        }
        { //::Geometry::Transform3D::zy
        
            typedef double ( ::Geometry::Transform3D::*zy_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "zy"
                , zy_function_type( &::Geometry::Transform3D::zy ) );
        
        }
        { //::Geometry::Transform3D::zz
        
            typedef double ( ::Geometry::Transform3D::*zz_function_type )(  ) const;
            
            Transform3D_exposer.def( 
                "zz"
                , zz_function_type( &::Geometry::Transform3D::zz ) );
        
        }
        Transform3D_exposer.def_readonly( "Identity", Geometry::Transform3D::Identity );
    }

}
