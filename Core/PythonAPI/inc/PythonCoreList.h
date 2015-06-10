#ifndef PYTHONCORELIST_H
#define PYTHONCORELIST_H

//! list of files to process with Py++

#include "IAxis.h"
#include "AttLimits.h"
#include "FixedBinAxis.h"
#include "VariableBinAxis.h"
#include "ConstKBinAxis.h"
#include "CustomBinAxis.h"
#include "BasicVector3D.h"
#include "BAVersion.h"
#include "Bin.h"
#include "Crystal.h"
#include "Distributions.h"
#include "FTDistributions.h"
#include "FormFactorAnisoPyramid.h"
#include "FormFactorBox.h"
#include "FormFactorCone.h"
#include "FormFactorCone6.h"
#include "FormFactorCrystal.h"
#include "FormFactorCuboctahedron.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorEllipsoidalCylinder.h"
#include "FormFactorFullSphere.h"
#include "FormFactorFullSpheroid.h"
#include "FormFactorGauss.h"
#include "FormFactorHemiEllipsoid.h"
#include "FormFactorInfLongBox.h"
#include "FormFactorInfLongRipple1.h"
#include "FormFactorInfLongRipple2.h"
#include "FormFactorLorentz.h"
#include "FormFactorPrism3.h"
#include "FormFactorPrism6.h"
#include "FormFactorPyramid.h"
#include "FormFactorRipple1.h"
#include "FormFactorRipple2.h"
#include "FormFactorSphereGaussianRadius.h"
#include "FormFactorSphereLogNormalRadius.h"
#include "FormFactorSphereUniformRadius.h"
#include "FormFactorTetrahedron.h"
#include "FormFactorTrivial.h"
#include "FormFactorTruncatedCube.h"
#include "FormFactorTruncatedSphere.h"
#include "FormFactorTruncatedSpheroid.h"
#include "FormFactorWeighted.h"
#include "HomogeneousMaterial.h"
#include "HomogeneousMagneticMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "ILayout.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "IntensityDataFunctions.h"
#include "IMaterial.h"
#include "IObserver.h"
#include "IParameterized.h"
#include "IResolutionFunction2D.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Instrument.h"
#include "InterferenceFunction1DLattice.h"
#include "InterferenceFunctionRadialParaCrystal.h"
#include "InterferenceFunction2DLattice.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "InterferenceFunctionNone.h"
#include "Lattice.h"
#include "Lattice1DIFParameters.h"
#include "Lattice2DIFParameters.h"
#include "ParticleComposition.h"
#include "Layer.h"
#include "LayerRoughness.h"
#include "MathFunctions.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "OffSpecSimulation.h"
#include "OutputData.h"
#include "IntensityDataIOFactory.h"
#include "OutputDataFunctions.h"
#include "ParameterDistribution.h"
#include "ParameterPool.h"
#include "IParticle.h"
#include "Particle.h"
#include "ParticleDistribution.h"
#include "ParticleCoreShell.h"
#include "ParticleLayout.h"
#include "PythonOutputData.h"
#include "RealParameterWrapper.h"
#include "ResolutionFunction2DGaussian.h"
#include "Rotations.h"
#include "SpecularSimulation.h"
#include "GISASSimulation.h"
#include "SimulationParameters.h"
#include "ThreadInfo.h"
#include "Types.h"
#include "Units.h"
#include "BAVersion.h"
#include "MessageService.h"

//! file containig additional exposers
#include "PythonCoreExposer.h"


#endif // PYTHONCORELIST_H
