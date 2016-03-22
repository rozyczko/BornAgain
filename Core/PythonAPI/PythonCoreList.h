#ifndef PYTHONCORELIST_H
#define PYTHONCORELIST_H

//! list of files to process with Py++

#include "AttLimits.h"
#include "BasicVector3D.h"
#include "BAVersion.h"
#include "Bin.h"
#include "ConstKBinAxis.h"
#include "Crystal.h"
#include "CustomBinAxis.h"
#include "Distributions.h"
#include "Ellipse.h"
#include "FixedBinAxis.h"
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
#include "FormFactorLongBoxGauss.h"
#include "FormFactorLongBoxLorentz.h"
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
#include "FTDistributions.h"
#include "FTDecayFunctions.h"
#include "GISASSimulation.h"
#include "Histogram1D.h"
#include "Histogram2D.h"
#include "HomogeneousMaterial.h"
#include "HomogeneousMagneticMaterial.h"
#include "IAxis.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDetector2D.h"
#include "ILayout.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IHistogram.h"
#include "IInterferenceFunction.h"
#include "IntensityDataFunctions.h"
#include "IntensityDataIOFactory.h"
#include "IMaterial.h"
#include "Instrument.h"
#include "InterferenceFunction1DLattice.h"
#include "InterferenceFunctionRadialParaCrystal.h"
#include "InterferenceFunction2DLattice.h"
#include "InterferenceFunction2DParaCrystal.h"
#include "InterferenceFunctionNone.h"
#include "IObserver.h"
#include "IParameterized.h"
#include "IParticle.h"
#include "IResolutionFunction2D.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "IsGISAXSDetector.h"
#include "IShape2D.h"
#include "ISingleton.h"
#include "Lattice.h"
#include "Lattice1DParameters.h"
#include "Lattice2DParameters.h"
#include "Layer.h"
#include "LayerRoughness.h"
#include "Line.h"
#include "MathFunctions.h"
#include "MesoCrystal.h"
#include "MessageService.h"
#include "MultiLayer.h"
#include "OffSpecSimulation.h"
#include "OutputData.h"
#include "OutputDataFunctions.h"
#include "ParameterDistribution.h"
#include "ParameterPool.h"
#include "Particle.h"
#include "ParticleComposition.h"
#include "ParticleCoreShell.h"
#include "ParticleDistribution.h"
#include "ParticleLayout.h"
#include "Polygon.h"
#include "PythonOutputData.h"
#include "Rectangle.h"
#include "RectangularDetector.h"
#include "RealParameterWrapper.h"
#include "ResolutionFunction2DGaussian.h"
#include "Rotations.h"
#include "SpecularSimulation.h"
#include "SphericalDetector.h"
#include "SimulationParameters.h"
#include "ThreadInfo.h"
#include "Types.h"
#include "Units.h"
#include "VariableBinAxis.h"

//! file containig additional exposers
#include "PythonCoreExposer.h"


#endif // PYTHONCORELIST_H