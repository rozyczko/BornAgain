// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence 
//! @brief automatically generated boost::python code for PythonCoreAPI  

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "IFormFactor.pypp.h"

namespace bp = boost::python;

struct IFormFactor_wrapper : IFormFactor, bp::wrapper< IFormFactor > {

    IFormFactor_wrapper( )
    : IFormFactor( )
      , bp::wrapper< IFormFactor >(){
        // null constructor
    
    }

    virtual ::IFormFactor * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual void createDistributedFormFactors( ::std::vector< IFormFactor* > & form_factors, ::std::vector< double > & probabilities, ::std::size_t nbr_samples ) const  {
        if( bp::override func_createDistributedFormFactors = this->get_override( "createDistributedFormFactors" ) )
            func_createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
        else
            this->IFormFactor::createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
    }
    
    
    void default_createDistributedFormFactors( ::std::vector< IFormFactor* > & form_factors, ::std::vector< double > & probabilities, ::std::size_t nbr_samples ) const  {
        IFormFactor::createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
    }

    virtual ::complex_t evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, double alpha_i, double alpha_f ) const {
        bp::override func_evaluate = this->get_override( "evaluate" );
        return func_evaluate( boost::ref(k_i), boost::ref(k_f_bin), alpha_i, alpha_f );
    }

    virtual double getHeight(  ) const  {
        if( bp::override func_getHeight = this->get_override( "getHeight" ) )
            return func_getHeight(  );
        else
            return this->IFormFactor::getHeight(  );
    }
    
    
    double default_getHeight(  ) const  {
        return IFormFactor::getHeight( );
    }

    virtual int getNumberOfStochasticParameters(  ) const  {
        if( bp::override func_getNumberOfStochasticParameters = this->get_override( "getNumberOfStochasticParameters" ) )
            return func_getNumberOfStochasticParameters(  );
        else
            return this->IFormFactor::getNumberOfStochasticParameters(  );
    }
    
    
    int default_getNumberOfStochasticParameters(  ) const  {
        return IFormFactor::getNumberOfStochasticParameters( );
    }

    virtual double getRadius(  ) const  {
        if( bp::override func_getRadius = this->get_override( "getRadius" ) )
            return func_getRadius(  );
        else
            return this->IFormFactor::getRadius(  );
    }
    
    
    double default_getRadius(  ) const  {
        return IFormFactor::getRadius( );
    }

    virtual double getVolume(  ) const  {
        if( bp::override func_getVolume = this->get_override( "getVolume" ) )
            return func_getVolume(  );
        else
            return this->IFormFactor::getVolume(  );
    }
    
    
    double default_getVolume(  ) const  {
        return IFormFactor::getVolume( );
    }

    virtual bool isDistributedFormFactor(  ) const  {
        if( bp::override func_isDistributedFormFactor = this->get_override( "isDistributedFormFactor" ) )
            return func_isDistributedFormFactor(  );
        else
            return this->IFormFactor::isDistributedFormFactor(  );
    }
    
    
    bool default_isDistributedFormFactor(  ) const  {
        return IFormFactor::isDistributedFormFactor( );
    }

    virtual void setAmbientRefractiveIndex( ::complex_t const & refractive_index ) {
        if( bp::override func_setAmbientRefractiveIndex = this->get_override( "setAmbientRefractiveIndex" ) )
            func_setAmbientRefractiveIndex( boost::ref(refractive_index) );
        else
            this->IFormFactor::setAmbientRefractiveIndex( boost::ref(refractive_index) );
    }
    
    
    void default_setAmbientRefractiveIndex( ::complex_t const & refractive_index ) {
        IFormFactor::setAmbientRefractiveIndex( boost::ref(refractive_index) );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else
            return this->IParameterized::areParametersChanged(  );
    }
    
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else
            this->IParameterized::clearParameterPool(  );
    }
    
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else
            return this->IParameterized::createParameterTree(  );
    }
    
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else
            return this->ISample::getCompositeSample(  );
    }
    
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ISample::getCompositeSample( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else
            this->IParameterized::printParameters(  );
    }
    
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual void registerParameter( ::std::string const & name, double * parpointer ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer );
        }
        else{
            IParameterized::registerParameter( name, parpointer );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer ){
        if( dynamic_cast< IFormFactor_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else
            return this->IParameterized::setParameterValue( name, value );
    }
    
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else
            this->IParameterized::setParametersAreChanged(  );
    }
    
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

};

void register_IFormFactor_class(){

    { //::IFormFactor
        typedef bp::class_< IFormFactor_wrapper, bp::bases< ISample >, boost::noncopyable > IFormFactor_exposer_t;
        IFormFactor_exposer_t IFormFactor_exposer = IFormFactor_exposer_t( "IFormFactor", bp::init< >() );
        bp::scope IFormFactor_scope( IFormFactor_exposer );
        { //::IFormFactor::clone
        
            typedef ::IFormFactor * ( ::IFormFactor::*clone_function_type )(  ) const;
            
            IFormFactor_exposer.def( 
                "clone"
                , bp::pure_virtual( clone_function_type(&::IFormFactor::clone) )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IFormFactor::createDistributedFormFactors
        
            typedef void ( ::IFormFactor::*createDistributedFormFactors_function_type )( ::std::vector< IFormFactor* > &,::std::vector< double > &,::std::size_t ) const;
            typedef void ( IFormFactor_wrapper::*default_createDistributedFormFactors_function_type )( ::std::vector< IFormFactor* > &,::std::vector< double > &,::std::size_t ) const;
            
            IFormFactor_exposer.def( 
                "createDistributedFormFactors"
                , createDistributedFormFactors_function_type(&::IFormFactor::createDistributedFormFactors)
                , default_createDistributedFormFactors_function_type(&IFormFactor_wrapper::default_createDistributedFormFactors)
                , ( bp::arg("form_factors"), bp::arg("probabilities"), bp::arg("nbr_samples") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IFormFactor::evaluate
        
            typedef ::complex_t ( ::IFormFactor::*evaluate_function_type )( ::cvector_t const &,::Bin1DCVector const &,double,double ) const;
            
            IFormFactor_exposer.def( 
                "evaluate"
                , bp::pure_virtual( evaluate_function_type(&::IFormFactor::evaluate) )
                , ( bp::arg("k_i"), bp::arg("k_f_bin"), bp::arg("alpha_i"), bp::arg("alpha_f") ) );
        
        }
        { //::IFormFactor::getHeight
        
            typedef double ( ::IFormFactor::*getHeight_function_type )(  ) const;
            typedef double ( IFormFactor_wrapper::*default_getHeight_function_type )(  ) const;
            
            IFormFactor_exposer.def( 
                "getHeight"
                , getHeight_function_type(&::IFormFactor::getHeight)
                , default_getHeight_function_type(&IFormFactor_wrapper::default_getHeight) );
        
        }
        { //::IFormFactor::getNumberOfStochasticParameters
        
            typedef int ( ::IFormFactor::*getNumberOfStochasticParameters_function_type )(  ) const;
            typedef int ( IFormFactor_wrapper::*default_getNumberOfStochasticParameters_function_type )(  ) const;
            
            IFormFactor_exposer.def( 
                "getNumberOfStochasticParameters"
                , getNumberOfStochasticParameters_function_type(&::IFormFactor::getNumberOfStochasticParameters)
                , default_getNumberOfStochasticParameters_function_type(&IFormFactor_wrapper::default_getNumberOfStochasticParameters) );
        
        }
        { //::IFormFactor::getRadius
        
            typedef double ( ::IFormFactor::*getRadius_function_type )(  ) const;
            typedef double ( IFormFactor_wrapper::*default_getRadius_function_type )(  ) const;
            
            IFormFactor_exposer.def( 
                "getRadius"
                , getRadius_function_type(&::IFormFactor::getRadius)
                , default_getRadius_function_type(&IFormFactor_wrapper::default_getRadius) );
        
        }
        { //::IFormFactor::getVolume
        
            typedef double ( ::IFormFactor::*getVolume_function_type )(  ) const;
            typedef double ( IFormFactor_wrapper::*default_getVolume_function_type )(  ) const;
            
            IFormFactor_exposer.def( 
                "getVolume"
                , getVolume_function_type(&::IFormFactor::getVolume)
                , default_getVolume_function_type(&IFormFactor_wrapper::default_getVolume) );
        
        }
        { //::IFormFactor::isDistributedFormFactor
        
            typedef bool ( ::IFormFactor::*isDistributedFormFactor_function_type )(  ) const;
            typedef bool ( IFormFactor_wrapper::*default_isDistributedFormFactor_function_type )(  ) const;
            
            IFormFactor_exposer.def( 
                "isDistributedFormFactor"
                , isDistributedFormFactor_function_type(&::IFormFactor::isDistributedFormFactor)
                , default_isDistributedFormFactor_function_type(&IFormFactor_wrapper::default_isDistributedFormFactor) );
        
        }
        { //::IFormFactor::setAmbientRefractiveIndex
        
            typedef void ( ::IFormFactor::*setAmbientRefractiveIndex_function_type )( ::complex_t const & ) ;
            typedef void ( IFormFactor_wrapper::*default_setAmbientRefractiveIndex_function_type )( ::complex_t const & ) ;
            
            IFormFactor_exposer.def( 
                "setAmbientRefractiveIndex"
                , setAmbientRefractiveIndex_function_type(&::IFormFactor::setAmbientRefractiveIndex)
                , default_setAmbientRefractiveIndex_function_type(&IFormFactor_wrapper::default_setAmbientRefractiveIndex)
                , ( bp::arg("refractive_index") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( IFormFactor_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            IFormFactor_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&IFormFactor_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( IFormFactor_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            IFormFactor_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&IFormFactor_wrapper::default_clearParameterPool) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( IFormFactor_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            IFormFactor_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&IFormFactor_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ISample::*getCompositeSample_function_type )(  ) const;
            typedef ::ICompositeSample const * ( IFormFactor_wrapper::*default_getCompositeSample_function_type )(  ) const;
            
            IFormFactor_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&IFormFactor_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( IFormFactor_wrapper::*default_printParameters_function_type )(  ) const;
            
            IFormFactor_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&IFormFactor_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            IFormFactor_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &IFormFactor_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( IFormFactor_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            IFormFactor_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&IFormFactor_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( IFormFactor_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            IFormFactor_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&IFormFactor_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
