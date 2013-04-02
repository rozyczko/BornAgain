// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "Bin.h"
#include "Crystal.h"
#include "DiffuseParticleInfo.h"
#include "FTDistributions.h"
#include "FormFactorBox.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorParallelepiped.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Instrument.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "InterferenceFunction2DLattice.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "InterferenceFunctionNone.h"
#include "IResolutionFunction2D.h"
#include "Lattice.h"
#include "Lattice2DIFParameters.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "Lattice2DIFParameters.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "Particle.h"
#include "ParticleBuilder.h"
#include "ParticleCoreShell.h"
#include "ParticleDecoration.h"
#include "OutputData.h"
#include "OutputDataIOFactory.h"
#include "ParticleInfo.h"
#include "PositionParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Simulation.h"
#include "SimulationParameters.h"
#include "IStochasticParameter.h"
#include "ResolutionFunction2DSimple.h"
#include "StochasticGaussian.h"
#include "StochasticSampledParameter.h"
#include "StochasticDoubleGate.h"
#include "Transform3D.h"
#include "Types.h"
#include "Units.h"
#include "ndimdata_t.pypp.h"

namespace bp = boost::python;

void register_ndimdata_t_class(){

    bp::class_< OutputData< double >, boost::noncopyable >( "ndimdata_t", bp::init< >() )    
        .def( 
            "addAxis"
            , (void ( ::OutputData<double>::* )( ::IAxis const & ) )( &::OutputData< double >::addAxis )
            , ( bp::arg("new_axis") ) )    
        .def( 
            "addAxis"
            , (void ( ::OutputData<double>::* )( ::std::string const &,::size_t,double,double ) )( &::OutputData< double >::addAxis )
            , ( bp::arg("name"), bp::arg("size"), bp::arg("start"), bp::arg("end") ) )    
        .def( 
            "addMask"
            , (void ( ::OutputData<double>::* )( ::Mask const & ) )( &::OutputData< double >::addMask )
            , ( bp::arg("mask") ) )    
        .def( 
            "clear"
            , (void ( ::OutputData<double>::* )(  ) )( &::OutputData< double >::clear ) )    
        .def( 
            "clone"
            , (::OutputData< double > * ( ::OutputData<double>::* )(  ) const)( &::OutputData< double >::clone )
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "copyFrom"
            , (void ( ::OutputData<double>::* )( ::OutputData< double > const & ) )( &::OutputData< double >::copyFrom )
            , ( bp::arg("other") ) )    
        .def( 
            "getAllSizes"
            , (::std::vector< unsigned long > ( ::OutputData<double>::* )(  ) const)( &::OutputData< double >::getAllSizes ) )    
        .def( 
            "getAllocatedSize"
            , (::size_t ( ::OutputData<double>::* )(  ) const)( &::OutputData< double >::getAllocatedSize ) )    
        .def( 
            "getAxis"
            , (::IAxis const * ( ::OutputData<double>::* )( ::size_t ) const)( &::OutputData< double >::getAxis )
            , ( bp::arg("index") )
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "getAxis"
            , (::IAxis const * ( ::OutputData<double>::* )( ::std::string const & ) const)( &::OutputData< double >::getAxis )
            , ( bp::arg("label") )
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "getAxisIndex"
            , (::size_t ( ::OutputData<double>::* )( ::std::string const & ) const)( &::OutputData< double >::getAxisIndex )
            , ( bp::arg("label") ) )    
        .def( 
            "getBinOfAxis"
            , (::Bin1D ( ::OutputData<double>::* )( ::std::string const &,::size_t ) const)( &::OutputData< double >::getBinOfAxis )
            , ( bp::arg("axis_name"), bp::arg("index") ) )    
        .def( 
            "getIndexOfAxis"
            , (::size_t ( ::OutputData<double>::* )( ::std::string const &,::size_t ) const)( &::OutputData< double >::getIndexOfAxis )
            , ( bp::arg("axis_name"), bp::arg("total_index") ) )    
        .def( 
            "getMask"
            , (::Mask * ( ::OutputData<double>::* )(  ) const)( &::OutputData< double >::getMask )
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "getRank"
            , (::size_t ( ::OutputData<double>::* )(  ) const)( &::OutputData< double >::getRank ) )    
        .def( 
            "getRawDataVector"
            , (::std::vector< double > ( ::OutputData<double>::* )(  ) const)( &::OutputData< double >::getRawDataVector ) )    
        .def( 
            "getValueOfAxis"
            , (double ( ::OutputData<double>::* )( ::std::string const &,::size_t ) const)( &::OutputData< double >::getValueOfAxis )
            , ( bp::arg("axis_name"), bp::arg("index") ) )    
        .def( 
            "hasSameDimensions"
            , (bool ( ::OutputData<double>::* )( ::OutputData< double > const & ) const)( &::OutputData< double >::hasSameDimensions )
            , ( bp::arg("right") ) )    
        .def( 
            "hasSameShape"
            , (bool ( ::OutputData<double>::* )( ::OutputData< double > const & ) const)( &::OutputData< double >::hasSameShape )
            , ( bp::arg("right") ) )    
        .def( bp::self *= bp::self )    
        .def( bp::self += bp::self )    
        .def( bp::self -= bp::self )    
        .def( bp::self /= bp::self )    
        .def( 
            "__getitem__"
            , (double & ( ::OutputData<double>::* )( ::size_t ) )( &::OutputData< double >::operator[] )
            , ( bp::arg("index") )
            , bp::return_value_policy< bp::copy_non_const_reference >() )    
        .def( 
            "__getitem__"
            , (double const & ( ::OutputData<double>::* )( ::size_t ) const)( &::OutputData< double >::operator[] )
            , ( bp::arg("index") )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "removeAllMasks"
            , (void ( ::OutputData<double>::* )(  ) )( &::OutputData< double >::removeAllMasks ) )    
        .def( 
            "scaleAll"
            , (void ( ::OutputData<double>::* )( double const & ) )( &::OutputData< double >::scaleAll )
            , ( bp::arg("factor") ) )    
        .def( 
            "setAllTo"
            , (void ( ::OutputData<double>::* )( double const & ) )( &::OutputData< double >::setAllTo )
            , ( bp::arg("value") ) )    
        .def( 
            "setMask"
            , (void ( ::OutputData<double>::* )( ::Mask const & ) )( &::OutputData< double >::setMask )
            , ( bp::arg("mask") ) )    
        .def( 
            "setRawDataVector"
            , (void ( ::OutputData<double>::* )( ::std::vector< double > const & ) )( &::OutputData< double >::setRawDataVector )
            , ( bp::arg("data_vector") ) )    
        .def( 
            "toCoordinate"
            , (int ( ::OutputData<double>::* )( ::size_t,::size_t ) const)( &::OutputData< double >::toCoordinate )
            , ( bp::arg("index"), bp::arg("i_selected_axis") ) )    
        .def( 
            "toCoordinates"
            , (::std::vector< int > ( ::OutputData<double>::* )( ::size_t ) const)( &::OutputData< double >::toCoordinates )
            , ( bp::arg("index") ) )    
        .def( 
            "toIndex"
            , (::size_t ( ::OutputData<double>::* )( ::std::vector< int > ) const)( &::OutputData< double >::toIndex )
            , ( bp::arg("coordinates") ) )    
        .def( 
            "totalSum"
            , (double ( ::OutputData<double>::* )(  ) const)( &::OutputData< double >::totalSum ) )    
        .def("__setitem__", &pyplusplus_setitem<OutputData<double >,int,double> );

}