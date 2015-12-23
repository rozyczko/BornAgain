// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "IsGISAXSDetector.pypp.h"

namespace bp = boost::python;

struct IsGISAXSDetector_wrapper : IsGISAXSDetector, bp::wrapper< IsGISAXSDetector > {

    IsGISAXSDetector_wrapper( )
    : IsGISAXSDetector( )
      , bp::wrapper< IsGISAXSDetector >(){
        // null constructor
    m_pyobj = 0;
    }

    IsGISAXSDetector_wrapper(::IsGISAXSDetector const & other )
    : IsGISAXSDetector( boost::ref(other) )
      , bp::wrapper< IsGISAXSDetector >(){
        // copy constructor
    m_pyobj = 0;
    }

    virtual ::IsGISAXSDetector * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->IsGISAXSDetector::clone(  );
        }
    }
    
    ::IsGISAXSDetector * default_clone(  ) const  {
        return IsGISAXSDetector::clone( );
    }

    PyObject* m_pyobj;

};

void register_IsGISAXSDetector_class(){

    { //::IsGISAXSDetector
        typedef bp::class_< IsGISAXSDetector_wrapper, bp::bases< SphericalDetector >, std::auto_ptr< IsGISAXSDetector_wrapper > > IsGISAXSDetector_exposer_t;
        IsGISAXSDetector_exposer_t IsGISAXSDetector_exposer = IsGISAXSDetector_exposer_t( "IsGISAXSDetector", "A spherical detector used for validation with IsGISAXS results.", bp::init< >() );
        bp::scope IsGISAXSDetector_scope( IsGISAXSDetector_exposer );
        IsGISAXSDetector_exposer.def( bp::init< IsGISAXSDetector const & >(( bp::arg("other") )) );
        { //::IsGISAXSDetector::clone
        
            typedef ::IsGISAXSDetector * ( ::IsGISAXSDetector::*clone_function_type)(  ) const;
            typedef ::IsGISAXSDetector * ( IsGISAXSDetector_wrapper::*default_clone_function_type)(  ) const;
            
            IsGISAXSDetector_exposer.def( 
                "clone"
                , clone_function_type(&::IsGISAXSDetector::clone)
                , default_clone_function_type(&IsGISAXSDetector_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IsGISAXSDetector::operator=
        
            typedef ::IsGISAXSDetector & ( ::IsGISAXSDetector::*assign_function_type)( ::IsGISAXSDetector const & ) ;
            
            IsGISAXSDetector_exposer.def( 
                "assign"
                , assign_function_type( &::IsGISAXSDetector::operator= )
                , ( bp::arg("other") )
                , bp::return_self< >() );
        
        }
    }

}
