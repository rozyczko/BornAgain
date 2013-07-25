#include "IsGISAXS02Builder.h"
#include "MultiLayer.h"
#include "ParticleDecoration.h"
#include "MaterialManager.h"
#include "FormFactorCylinder.h"
#include "FormFactorPrism3.h"
#include "Units.h"
#include "InterferenceFunctionNone.h"
#include "StochasticSampledParameter.h"
#include "StochasticGaussian.h"
#include "ParticleBuilder.h"



IsGISAXS02Builder::IsGISAXS02Builder()
    : m_radius1(5*Units::nanometer)
    , m_radius2(10*Units::nanometer)
    , m_height1(5*Units::nanometer)
    , m_height2(10*Units::nanometer)
    , m_sigma1_ratio(0.2)
    , m_sigma2_ratio(0.02)
{
    init_parameters();
}


void IsGISAXS02Builder::init_parameters()
{
    clearParameterPool();
    registerParameter("radius1", &m_radius1);
    registerParameter("radius2", &m_radius2);
    registerParameter("height1", &m_height1);
    registerParameter("height2", &m_height2);
    registerParameter("sigma1_ratio", &m_sigma1_ratio);
    registerParameter("sigma2_ratio", &m_sigma2_ratio);
}


ISample *IsGISAXS02Builder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    const IMaterial *p_air_material = MaterialManager::getHomogeneousMaterial("Air", 0.0, 0.0);
    Layer air_layer;
    air_layer.setMaterial(p_air_material);

    ParticleDecoration particle_decoration;
    complex_t n_particle(1.0-6e-4, 2e-8);

    // preparing nano particles prototypes for seeding layer's particle_decoration
    FormFactorCylinder *p_ff_cylinder1 = new FormFactorCylinder(m_height1, m_radius1);
    Particle cylinder1(n_particle, p_ff_cylinder1 );

    FormFactorCylinder *p_ff_cylinder2 = new FormFactorCylinder(m_height2, m_radius2);
    Particle cylinder2(n_particle, p_ff_cylinder2 );

    // radius of nanoparticles will be sampled with gaussian probability
    int nbins=150;
    double sigma1 = m_radius1*m_sigma1_ratio;
    double sigma2 = m_radius2*m_sigma2_ratio;
    int nfwhm(3); // to have xmin=average-nfwhm*FWHM, xmax=average+nfwhm*FWHM (nfwhm = xR/2, where xR is what is defined in isgisaxs *.inp file)
    StochasticDoubleGaussian sg1(m_radius1, sigma1);
    StochasticDoubleGaussian sg2(m_radius2, sigma2);
    StochasticSampledParameter par1(sg1, nbins, nfwhm);
    StochasticSampledParameter par2(sg2, nbins, nfwhm);

    // building nano particles
    ParticleBuilder builder;
    builder.setPrototype(cylinder1,"/Particle/FormFactorCylinder/radius", par1, 0.95);
    builder.plantParticles(particle_decoration);

    builder.setPrototype(cylinder2,"/Particle/FormFactorCylinder/radius", par2, 0.05);
    builder.plantParticles(particle_decoration);

    particle_decoration.addInterferenceFunction(new InterferenceFunctionNone());

    air_layer.setDecoration(particle_decoration);

    multi_layer->addLayer(air_layer);

    return multi_layer;
}

