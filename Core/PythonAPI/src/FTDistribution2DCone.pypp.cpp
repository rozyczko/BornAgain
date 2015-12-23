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
#include "FTDistribution2DCone.pypp.h"

namespace bp = boost::python;

struct FTDistribution2DCone_wrapper : FTDistribution2DCone, bp::wrapper< FTDistribution2DCone > {

    FTDistribution2DCone_wrapper(FTDistribution2DCone const & arg )
    : FTDistribution2DCone( arg )
      , bp::wrapper< FTDistribution2DCone >(){
        // copy constructor
        m_pyobj = 0;
    }

    FTDistribution2DCone_wrapper(double coherence_length_x, double coherence_length_y )
    : FTDistribution2DCone( coherence_length_x, coherence_length_y )
      , bp::wrapper< FTDistribution2DCone >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::FTDistribution2DCone * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FTDistribution2DCone::clone(  );
        }
    }
    
    ::FTDistribution2DCone * default_clone(  ) const  {
        return FTDistribution2DCone::clone( );
    }

    virtual double evaluate( double qx, double qy ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( qx, qy );
        else{
            return this->FTDistribution2DCone::evaluate( qx, qy );
        }
    }
    
    double default_evaluate( double qx, double qy ) const  {
        return FTDistribution2DCone::evaluate( qx, qy );
    }

    virtual double evaluateLattice( double qx, double qy ) const  {
        if( bp::override func_evaluateLattice = this->get_override( "evaluateLattice" ) )
            return func_evaluateLattice( qx, qy );
        else{
            return this->IFTDistribution2D::evaluateLattice( qx, qy );
        }
    }
    
    double default_evaluateLattice( double qx, double qy ) const  {
        return IFTDistribution2D::evaluateLattice( qx, qy );
    }

    PyObject* m_pyobj;

};

void register_FTDistribution2DCone_class(){

    { //::FTDistribution2DCone
        typedef bp::class_< FTDistribution2DCone_wrapper, bp::bases< IFTDistribution2D >, std::auto_ptr< FTDistribution2DCone_wrapper > > FTDistribution2DCone_exposer_t;
        FTDistribution2DCone_exposer_t FTDistribution2DCone_exposer = FTDistribution2DCone_exposer_t( "FTDistribution2DCone", "2 dimensional cone distribution in Fourier space.", bp::init< double, double >(( bp::arg("coherence_length_x"), bp::arg("coherence_length_y") )) );
        bp::scope FTDistribution2DCone_scope( FTDistribution2DCone_exposer );
        { //::FTDistribution2DCone::clone
        
            typedef ::FTDistribution2DCone * ( ::FTDistribution2DCone::*clone_function_type)(  ) const;
            typedef ::FTDistribution2DCone * ( FTDistribution2DCone_wrapper::*default_clone_function_type)(  ) const;
            
            FTDistribution2DCone_exposer.def( 
                "clone"
                , clone_function_type(&::FTDistribution2DCone::clone)
                , default_clone_function_type(&FTDistribution2DCone_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FTDistribution2DCone::evaluate
        
            typedef double ( ::FTDistribution2DCone::*evaluate_function_type)( double,double ) const;
            typedef double ( FTDistribution2DCone_wrapper::*default_evaluate_function_type)( double,double ) const;
            
            FTDistribution2DCone_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::FTDistribution2DCone::evaluate)
                , default_evaluate_function_type(&FTDistribution2DCone_wrapper::default_evaluate)
                , ( bp::arg("qx"), bp::arg("qy") ) );
        
        }
        { //::IFTDistribution2D::evaluateLattice
        
            typedef double ( ::IFTDistribution2D::*evaluateLattice_function_type)( double,double ) const;
            typedef double ( FTDistribution2DCone_wrapper::*default_evaluateLattice_function_type)( double,double ) const;
            
            FTDistribution2DCone_exposer.def( 
                "evaluateLattice"
                , evaluateLattice_function_type(&::IFTDistribution2D::evaluateLattice)
                , default_evaluateLattice_function_type(&FTDistribution2DCone_wrapper::default_evaluateLattice)
                , ( bp::arg("qx"), bp::arg("qy") ) );
        
        }
    }

}
