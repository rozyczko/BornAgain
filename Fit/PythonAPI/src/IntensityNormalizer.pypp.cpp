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
#include "PythonFitList.h"
#include "IntensityNormalizer.pypp.h"

namespace bp = boost::python;

struct IntensityNormalizer_wrapper : IntensityNormalizer, bp::wrapper< IntensityNormalizer > {

    IntensityNormalizer_wrapper(IntensityNormalizer const & arg )
    : IntensityNormalizer( arg )
      , bp::wrapper< IntensityNormalizer >(){
        // copy constructor
        m_pyobj = 0;
    }

    IntensityNormalizer_wrapper(double scale=1.0e+0, double shift=0.0 )
    : IntensityNormalizer( scale, shift )
      , bp::wrapper< IntensityNormalizer >(){
        // constructor
    m_pyobj = 0;
    }

    virtual void apply( ::OutputData< double > & data ) const  {
        if( bp::override func_apply = this->get_override( "apply" ) )
            func_apply( boost::ref(data) );
        else{
            this->IntensityNormalizer::apply( boost::ref(data) );
        }
    }
    
    void default_apply( ::OutputData< double > & data ) const  {
        IntensityNormalizer::apply( boost::ref(data) );
    }

    virtual ::IntensityNormalizer * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->IntensityNormalizer::clone(  );
        }
    }
    
    ::IntensityNormalizer * default_clone(  ) const  {
        return IntensityNormalizer::clone( );
    }

    virtual ::OutputData< double > * createNormalizedData( ::OutputData< double > const & data ) const  {
        if( bp::override func_createNormalizedData = this->get_override( "createNormalizedData" ) )
            return func_createNormalizedData( boost::ref(data) );
        else{
            return this->IntensityNormalizer::createNormalizedData( boost::ref(data) );
        }
    }
    
    ::OutputData< double > * default_createNormalizedData( ::OutputData< double > const & data ) const  {
        return IntensityNormalizer::createNormalizedData( boost::ref(data) );
    }

    virtual void setMaximumIntensity( double max_intensity ) {
        if( bp::override func_setMaximumIntensity = this->get_override( "setMaximumIntensity" ) )
            func_setMaximumIntensity( max_intensity );
        else{
            this->IntensityNormalizer::setMaximumIntensity( max_intensity );
        }
    }
    
    void default_setMaximumIntensity( double max_intensity ) {
        IntensityNormalizer::setMaximumIntensity( max_intensity );
    }

    PyObject* m_pyobj;

};

void register_IntensityNormalizer_class(){

    { //::IntensityNormalizer
        typedef bp::class_< IntensityNormalizer_wrapper, bp::bases< IIntensityNormalizer >, std::auto_ptr< IntensityNormalizer_wrapper > > IntensityNormalizer_exposer_t;
        IntensityNormalizer_exposer_t IntensityNormalizer_exposer = IntensityNormalizer_exposer_t( "IntensityNormalizer", "Standard OutputData normalizer, with configurable max_intensity.", bp::init< bp::optional< double, double > >(( bp::arg("scale")=1.0e+0, bp::arg("shift")=0.0 )) );
        bp::scope IntensityNormalizer_scope( IntensityNormalizer_exposer );
        { //::IntensityNormalizer::apply
        
            typedef void ( ::IntensityNormalizer::*apply_function_type)( ::OutputData< double > & ) const;
            typedef void ( IntensityNormalizer_wrapper::*default_apply_function_type)( ::OutputData< double > & ) const;
            
            IntensityNormalizer_exposer.def( 
                "apply"
                , apply_function_type(&::IntensityNormalizer::apply)
                , default_apply_function_type(&IntensityNormalizer_wrapper::default_apply)
                , ( bp::arg("data") ) );
        
        }
        { //::IntensityNormalizer::clone
        
            typedef ::IntensityNormalizer * ( ::IntensityNormalizer::*clone_function_type)(  ) const;
            typedef ::IntensityNormalizer * ( IntensityNormalizer_wrapper::*default_clone_function_type)(  ) const;
            
            IntensityNormalizer_exposer.def( 
                "clone"
                , clone_function_type(&::IntensityNormalizer::clone)
                , default_clone_function_type(&IntensityNormalizer_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IntensityNormalizer::createNormalizedData
        
            typedef ::OutputData< double > * ( ::IntensityNormalizer::*createNormalizedData_function_type)( ::OutputData< double > const & ) const;
            typedef ::OutputData< double > * ( IntensityNormalizer_wrapper::*default_createNormalizedData_function_type)( ::OutputData< double > const & ) const;
            
            IntensityNormalizer_exposer.def( 
                "createNormalizedData"
                , createNormalizedData_function_type(&::IntensityNormalizer::createNormalizedData)
                , default_createNormalizedData_function_type(&IntensityNormalizer_wrapper::default_createNormalizedData)
                , ( bp::arg("data") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IntensityNormalizer::setMaximumIntensity
        
            typedef void ( ::IntensityNormalizer::*setMaximumIntensity_function_type)( double ) ;
            typedef void ( IntensityNormalizer_wrapper::*default_setMaximumIntensity_function_type)( double ) ;
            
            IntensityNormalizer_exposer.def( 
                "setMaximumIntensity"
                , setMaximumIntensity_function_type(&::IntensityNormalizer::setMaximumIntensity)
                , default_setMaximumIntensity_function_type(&IntensityNormalizer_wrapper::default_setMaximumIntensity)
                , ( bp::arg("max_intensity") ) );
        
        }
    }

}
