// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "DistributionCosine.pypp.h"

namespace bp = boost::python;

struct DistributionCosine_wrapper : DistributionCosine, bp::wrapper< DistributionCosine > {

    DistributionCosine_wrapper(DistributionCosine const & arg )
    : DistributionCosine( arg )
      , bp::wrapper< DistributionCosine >(){
        // copy constructor
        m_pyobj = 0;
    }

    DistributionCosine_wrapper( )
    : DistributionCosine( )
      , bp::wrapper< DistributionCosine >(){
        // null constructor
    m_pyobj = 0;
    }

    DistributionCosine_wrapper(double mean, double sigma )
    : DistributionCosine( mean, sigma )
      , bp::wrapper< DistributionCosine >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::DistributionCosine * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->DistributionCosine::clone(  );
        }
    }
    
    ::DistributionCosine * default_clone(  ) const  {
        return DistributionCosine::clone( );
    }

    virtual ::std::vector< double > generateValueList( ::std::size_t nbr_samples, double sigma_factor ) const  {
        if( bp::override func_generateValueList = this->get_override( "generateValueList" ) )
            return func_generateValueList( nbr_samples, sigma_factor );
        else{
            return this->DistributionCosine::generateValueList( nbr_samples, sigma_factor );
        }
    }
    
    ::std::vector< double > default_generateValueList( ::std::size_t nbr_samples, double sigma_factor ) const  {
        return DistributionCosine::generateValueList( nbr_samples, sigma_factor );
    }

    virtual double getMean(  ) const  {
        if( bp::override func_getMean = this->get_override( "getMean" ) )
            return func_getMean(  );
        else{
            return this->DistributionCosine::getMean(  );
        }
    }
    
    double default_getMean(  ) const  {
        return DistributionCosine::getMean( );
    }

    virtual double probabilityDensity( double x ) const  {
        if( bp::override func_probabilityDensity = this->get_override( "probabilityDensity" ) )
            return func_probabilityDensity( x );
        else{
            return this->DistributionCosine::probabilityDensity( x );
        }
    }
    
    double default_probabilityDensity( double x ) const  {
        return DistributionCosine::probabilityDensity( x );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else{
            this->IParameterized::clearParameterPool(  );
        }
    }
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
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
        if( dynamic_cast< DistributionCosine_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else{
            return this->IParameterized::setParameterValue( name, value );
        }
    }
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

    PyObject* m_pyobj;

};

void register_DistributionCosine_class(){

    { //::DistributionCosine
        typedef bp::class_< DistributionCosine_wrapper, bp::bases< IDistribution1D >, std::auto_ptr< DistributionCosine_wrapper > > DistributionCosine_exposer_t;
        DistributionCosine_exposer_t DistributionCosine_exposer = DistributionCosine_exposer_t( "DistributionCosine", bp::init< >() );
        bp::scope DistributionCosine_scope( DistributionCosine_exposer );
        DistributionCosine_exposer.def( bp::init< double, double >(( bp::arg("mean"), bp::arg("sigma") )) );
        { //::DistributionCosine::clone
        
            typedef ::DistributionCosine * ( ::DistributionCosine::*clone_function_type)(  ) const;
            typedef ::DistributionCosine * ( DistributionCosine_wrapper::*default_clone_function_type)(  ) const;
            
            DistributionCosine_exposer.def( 
                "clone"
                , clone_function_type(&::DistributionCosine::clone)
                , default_clone_function_type(&DistributionCosine_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::DistributionCosine::generateValueList
        
            typedef ::std::vector< double > ( ::DistributionCosine::*generateValueList_function_type)( ::std::size_t,double ) const;
            typedef ::std::vector< double > ( DistributionCosine_wrapper::*default_generateValueList_function_type)( ::std::size_t,double ) const;
            
            DistributionCosine_exposer.def( 
                "generateValueList"
                , generateValueList_function_type(&::DistributionCosine::generateValueList)
                , default_generateValueList_function_type(&DistributionCosine_wrapper::default_generateValueList)
                , ( bp::arg("nbr_samples"), bp::arg("sigma_factor") ) );
        
        }
        { //::DistributionCosine::getMean
        
            typedef double ( ::DistributionCosine::*getMean_function_type)(  ) const;
            typedef double ( DistributionCosine_wrapper::*default_getMean_function_type)(  ) const;
            
            DistributionCosine_exposer.def( 
                "getMean"
                , getMean_function_type(&::DistributionCosine::getMean)
                , default_getMean_function_type(&DistributionCosine_wrapper::default_getMean) );
        
        }
        { //::DistributionCosine::probabilityDensity
        
            typedef double ( ::DistributionCosine::*probabilityDensity_function_type)( double ) const;
            typedef double ( DistributionCosine_wrapper::*default_probabilityDensity_function_type)( double ) const;
            
            DistributionCosine_exposer.def( 
                "probabilityDensity"
                , probabilityDensity_function_type(&::DistributionCosine::probabilityDensity)
                , default_probabilityDensity_function_type(&DistributionCosine_wrapper::default_probabilityDensity)
                , ( bp::arg("x") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( DistributionCosine_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            DistributionCosine_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&DistributionCosine_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( DistributionCosine_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            DistributionCosine_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&DistributionCosine_wrapper::default_clearParameterPool) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( DistributionCosine_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            DistributionCosine_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&DistributionCosine_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( DistributionCosine_wrapper::*default_printParameters_function_type)(  ) const;
            
            DistributionCosine_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&DistributionCosine_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            DistributionCosine_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &DistributionCosine_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( DistributionCosine_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            DistributionCosine_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&DistributionCosine_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( DistributionCosine_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            DistributionCosine_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&DistributionCosine_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
