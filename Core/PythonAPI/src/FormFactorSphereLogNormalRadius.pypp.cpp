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
#include "FormFactorSphereLogNormalRadius.pypp.h"

namespace bp = boost::python;

struct FormFactorSphereLogNormalRadius_wrapper : FormFactorSphereLogNormalRadius, bp::wrapper< FormFactorSphereLogNormalRadius > {

    FormFactorSphereLogNormalRadius_wrapper(double mean, double scale_param, ::std::size_t n_samples )
    : FormFactorSphereLogNormalRadius( mean, scale_param, n_samples )
      , bp::wrapper< FormFactorSphereLogNormalRadius >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::FormFactorSphereLogNormalRadius * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FormFactorSphereLogNormalRadius::clone(  );
        }
    }
    
    ::FormFactorSphereLogNormalRadius * default_clone(  ) const  {
        return FormFactorSphereLogNormalRadius::clone( );
    }

    virtual void createDistributedFormFactors( ::std::vector< IFormFactor* > & form_factors, ::std::vector< double > & probabilities, ::std::size_t nbr_samples ) const  {
        if( bp::override func_createDistributedFormFactors = this->get_override( "createDistributedFormFactors" ) )
            func_createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
        else{
            this->FormFactorSphereLogNormalRadius::createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
        }
    }
    
    void default_createDistributedFormFactors( ::std::vector< IFormFactor* > & form_factors, ::std::vector< double > & probabilities, ::std::size_t nbr_samples ) const  {
        FormFactorSphereLogNormalRadius::createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
    }

    virtual ::complex_t evaluate_for_q( ::cvector_t const & q ) const  {
        if( bp::override func_evaluate_for_q = this->get_override( "evaluate_for_q" ) )
            return func_evaluate_for_q( boost::ref(q) );
        else{
            return this->FormFactorSphereLogNormalRadius::evaluate_for_q( boost::ref(q) );
        }
    }
    
    ::complex_t default_evaluate_for_q( ::cvector_t const & q ) const  {
        return FormFactorSphereLogNormalRadius::evaluate_for_q( boost::ref(q) );
    }

    virtual double getHeight(  ) const  {
        if( bp::override func_getHeight = this->get_override( "getHeight" ) )
            return func_getHeight(  );
        else{
            return this->FormFactorSphereLogNormalRadius::getHeight(  );
        }
    }
    
    double default_getHeight(  ) const  {
        return FormFactorSphereLogNormalRadius::getHeight( );
    }

    virtual int getNumberOfStochasticParameters(  ) const  {
        if( bp::override func_getNumberOfStochasticParameters = this->get_override( "getNumberOfStochasticParameters" ) )
            return func_getNumberOfStochasticParameters(  );
        else{
            return this->FormFactorSphereLogNormalRadius::getNumberOfStochasticParameters(  );
        }
    }
    
    int default_getNumberOfStochasticParameters(  ) const  {
        return FormFactorSphereLogNormalRadius::getNumberOfStochasticParameters( );
    }

    virtual bool isDistributedFormFactor(  ) const  {
        if( bp::override func_isDistributedFormFactor = this->get_override( "isDistributedFormFactor" ) )
            return func_isDistributedFormFactor(  );
        else{
            return this->FormFactorSphereLogNormalRadius::isDistributedFormFactor(  );
        }
    }
    
    bool default_isDistributedFormFactor(  ) const  {
        return FormFactorSphereLogNormalRadius::isDistributedFormFactor( );
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

    virtual ::ISample * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->ISample::cloneInvertB(  );
        }
    }
    
    ::ISample * default_cloneInvertB(  ) const  {
        return ISample::cloneInvertB( );
    }

    virtual bool containsMagneticMaterial(  ) const  {
        if( bp::override func_containsMagneticMaterial = this->get_override( "containsMagneticMaterial" ) )
            return func_containsMagneticMaterial(  );
        else{
            return this->ISample::containsMagneticMaterial(  );
        }
    }
    
    bool default_containsMagneticMaterial(  ) const  {
        return ISample::containsMagneticMaterial( );
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

    virtual ::complex_t evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, ::Bin1D const & alpha_f_bin ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(k_i), boost::ref(k_f_bin), boost::ref(alpha_f_bin) );
        else{
            return this->IFormFactorBorn::evaluate( boost::ref(k_i), boost::ref(k_f_bin), boost::ref(alpha_f_bin) );
        }
    }
    
    ::complex_t default_evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, ::Bin1D const & alpha_f_bin ) const  {
        return IFormFactorBorn::evaluate( boost::ref(k_i), boost::ref(k_f_bin), boost::ref(alpha_f_bin) );
    }

    virtual ::ICompositeSample * getCompositeSample(  ) {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ISample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample * default_getCompositeSample(  ) {
        return ISample::getCompositeSample( );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ISample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ISample::getCompositeSample( );
    }

    virtual double getRadius(  ) const  {
        if( bp::override func_getRadius = this->get_override( "getRadius" ) )
            return func_getRadius(  );
        else{
            return this->IFormFactor::getRadius(  );
        }
    }
    
    double default_getRadius(  ) const  {
        return IFormFactor::getRadius( );
    }

    virtual double getVolume(  ) const  {
        if( bp::override func_getVolume = this->get_override( "getVolume" ) )
            return func_getVolume(  );
        else{
            return this->IFormFactorBorn::getVolume(  );
        }
    }
    
    double default_getVolume(  ) const  {
        return IFormFactorBorn::getVolume( );
    }

    virtual bool preprocess(  ) {
        if( bp::override func_preprocess = this->get_override( "preprocess" ) )
            return func_preprocess(  );
        else{
            return this->ISample::preprocess(  );
        }
    }
    
    bool default_preprocess(  ) {
        return ISample::preprocess( );
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

    virtual void printSampleTree(  ) {
        if( bp::override func_printSampleTree = this->get_override( "printSampleTree" ) )
            func_printSampleTree(  );
        else{
            this->ISample::printSampleTree(  );
        }
    }
    
    void default_printSampleTree(  ) {
        ISample::printSampleTree( );
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
        if( dynamic_cast< FormFactorSphereLogNormalRadius_wrapper * >( boost::addressof( inst ) ) ){
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

    virtual void transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        if( bp::override func_transferToCPP = this->get_override( "transferToCPP" ) )
            func_transferToCPP(  );
        else{
            this->ICloneable::transferToCPP(  );
        }
    }
    
    void default_transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        ICloneable::transferToCPP( );
    }

    PyObject* m_pyobj;

};

void register_FormFactorSphereLogNormalRadius_class(){

    { //::FormFactorSphereLogNormalRadius
        typedef bp::class_< FormFactorSphereLogNormalRadius_wrapper, bp::bases< IFormFactorBorn >, std::auto_ptr< FormFactorSphereLogNormalRadius_wrapper >, boost::noncopyable > FormFactorSphereLogNormalRadius_exposer_t;
        FormFactorSphereLogNormalRadius_exposer_t FormFactorSphereLogNormalRadius_exposer = FormFactorSphereLogNormalRadius_exposer_t( "FormFactorSphereLogNormalRadius", bp::init< double, double, std::size_t >(( bp::arg("mean"), bp::arg("scale_param"), bp::arg("n_samples") )) );
        bp::scope FormFactorSphereLogNormalRadius_scope( FormFactorSphereLogNormalRadius_exposer );
        { //::FormFactorSphereLogNormalRadius::clone
        
            typedef ::FormFactorSphereLogNormalRadius * ( ::FormFactorSphereLogNormalRadius::*clone_function_type)(  ) const;
            typedef ::FormFactorSphereLogNormalRadius * ( FormFactorSphereLogNormalRadius_wrapper::*default_clone_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "clone"
                , clone_function_type(&::FormFactorSphereLogNormalRadius::clone)
                , default_clone_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FormFactorSphereLogNormalRadius::createDistributedFormFactors
        
            typedef void ( ::FormFactorSphereLogNormalRadius::*createDistributedFormFactors_function_type)( ::std::vector< IFormFactor* > &,::std::vector< double > &,::std::size_t ) const;
            typedef void ( FormFactorSphereLogNormalRadius_wrapper::*default_createDistributedFormFactors_function_type)( ::std::vector< IFormFactor* > &,::std::vector< double > &,::std::size_t ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "createDistributedFormFactors"
                , createDistributedFormFactors_function_type(&::FormFactorSphereLogNormalRadius::createDistributedFormFactors)
                , default_createDistributedFormFactors_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_createDistributedFormFactors)
                , ( bp::arg("form_factors"), bp::arg("probabilities"), bp::arg("nbr_samples") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FormFactorSphereLogNormalRadius::evaluate_for_q
        
            typedef ::complex_t ( ::FormFactorSphereLogNormalRadius::*evaluate_for_q_function_type)( ::cvector_t const & ) const;
            typedef ::complex_t ( FormFactorSphereLogNormalRadius_wrapper::*default_evaluate_for_q_function_type)( ::cvector_t const & ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "evaluate_for_q"
                , evaluate_for_q_function_type(&::FormFactorSphereLogNormalRadius::evaluate_for_q)
                , default_evaluate_for_q_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_evaluate_for_q)
                , ( bp::arg("q") ) );
        
        }
        { //::FormFactorSphereLogNormalRadius::getHeight
        
            typedef double ( ::FormFactorSphereLogNormalRadius::*getHeight_function_type)(  ) const;
            typedef double ( FormFactorSphereLogNormalRadius_wrapper::*default_getHeight_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "getHeight"
                , getHeight_function_type(&::FormFactorSphereLogNormalRadius::getHeight)
                , default_getHeight_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_getHeight) );
        
        }
        { //::FormFactorSphereLogNormalRadius::getNumberOfStochasticParameters
        
            typedef int ( ::FormFactorSphereLogNormalRadius::*getNumberOfStochasticParameters_function_type)(  ) const;
            typedef int ( FormFactorSphereLogNormalRadius_wrapper::*default_getNumberOfStochasticParameters_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "getNumberOfStochasticParameters"
                , getNumberOfStochasticParameters_function_type(&::FormFactorSphereLogNormalRadius::getNumberOfStochasticParameters)
                , default_getNumberOfStochasticParameters_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_getNumberOfStochasticParameters) );
        
        }
        { //::FormFactorSphereLogNormalRadius::isDistributedFormFactor
        
            typedef bool ( ::FormFactorSphereLogNormalRadius::*isDistributedFormFactor_function_type)(  ) const;
            typedef bool ( FormFactorSphereLogNormalRadius_wrapper::*default_isDistributedFormFactor_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "isDistributedFormFactor"
                , isDistributedFormFactor_function_type(&::FormFactorSphereLogNormalRadius::isDistributedFormFactor)
                , default_isDistributedFormFactor_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_isDistributedFormFactor) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( FormFactorSphereLogNormalRadius_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( FormFactorSphereLogNormalRadius_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_clearParameterPool) );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type)(  ) const;
            typedef ::ISample * ( FormFactorSphereLogNormalRadius_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( FormFactorSphereLogNormalRadius_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( FormFactorSphereLogNormalRadius_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IFormFactorBorn::evaluate
        
            typedef ::complex_t ( ::IFormFactorBorn::*evaluate_function_type)( ::cvector_t const &,::Bin1DCVector const &,::Bin1D const & ) const;
            typedef ::complex_t ( FormFactorSphereLogNormalRadius_wrapper::*default_evaluate_function_type)( ::cvector_t const &,::Bin1DCVector const &,::Bin1D const & ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::IFormFactorBorn::evaluate)
                , default_evaluate_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_evaluate)
                , ( bp::arg("k_i"), bp::arg("k_f_bin"), bp::arg("alpha_f_bin") ) );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ISample::*getCompositeSample_function_type)(  ) ;
            typedef ::ICompositeSample * ( FormFactorSphereLogNormalRadius_wrapper::*default_getCompositeSample_function_type)(  ) ;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ISample::*getCompositeSample_function_type)(  ) const;
            typedef ::ICompositeSample const * ( FormFactorSphereLogNormalRadius_wrapper::*default_getCompositeSample_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IFormFactor::getRadius
        
            typedef double ( ::IFormFactor::*getRadius_function_type)(  ) const;
            typedef double ( FormFactorSphereLogNormalRadius_wrapper::*default_getRadius_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "getRadius"
                , getRadius_function_type(&::IFormFactor::getRadius)
                , default_getRadius_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_getRadius) );
        
        }
        { //::IFormFactorBorn::getVolume
        
            typedef double ( ::IFormFactorBorn::*getVolume_function_type)(  ) const;
            typedef double ( FormFactorSphereLogNormalRadius_wrapper::*default_getVolume_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "getVolume"
                , getVolume_function_type(&::IFormFactorBorn::getVolume)
                , default_getVolume_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_getVolume) );
        
        }
        { //::ISample::preprocess
        
            typedef bool ( ::ISample::*preprocess_function_type)(  ) ;
            typedef bool ( FormFactorSphereLogNormalRadius_wrapper::*default_preprocess_function_type)(  ) ;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "preprocess"
                , preprocess_function_type(&::ISample::preprocess)
                , default_preprocess_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_preprocess) );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( FormFactorSphereLogNormalRadius_wrapper::*default_printParameters_function_type)(  ) const;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_printParameters) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( FormFactorSphereLogNormalRadius_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_printSampleTree) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &FormFactorSphereLogNormalRadius_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( FormFactorSphereLogNormalRadius_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( FormFactorSphereLogNormalRadius_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_setParametersAreChanged) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( FormFactorSphereLogNormalRadius_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            FormFactorSphereLogNormalRadius_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&FormFactorSphereLogNormalRadius_wrapper::default_transferToCPP) );
        
        }
    }

}
