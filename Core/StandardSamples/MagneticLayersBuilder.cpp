// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/MagneticLayersBuilder.cpp
//! @brief    Implements class to build samples with magnetic layers
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "MagneticLayersBuilder.h"
#include "MaterialFactoryFuncs.h"
#include "BornAgainNamespace.h"
#include "FormFactorFullSphere.h"
#include "Layer.h"
#include "MultiLayer.h"
#include "Particle.h"
#include "ParticleLayout.h"
#include "RealParameter.h"
#include "Units.h"


MagneticSubstrateZeroFieldBuilder::MagneticSubstrateZeroFieldBuilder()
    : m_sphere_radius(5*Units::nanometer)
{}

MultiLayer*MagneticSubstrateZeroFieldBuilder::buildSample() const
{
    MultiLayer* multi_layer = new MultiLayer();

    kvector_t substr_field(0.0, 0.0, 0.0);
    kvector_t particle_field(0.1, 0.0, 0.0);
    Material air_material = HomogeneousMaterial("Air", 0.0, 0.0);
    Material substrate_material = HomogeneousMaterial("Substrate", 7e-6, 2e-8, substr_field);
    Material particle_material = HomogeneousMaterial("MagParticle", 6e-4, 2e-8, particle_field);

    ParticleLayout particle_layout;
    kvector_t position(0.0, 0.0, -10.0*Units::nanometer);
    FormFactorFullSphere ff_sphere(m_sphere_radius);
    Particle particle(particle_material, ff_sphere);
    particle_layout.addParticle(particle, 1.0, position);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);
    substrate_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}

MagneticRotationBuilder::MagneticRotationBuilder()
    : m_sphere_radius(5*Units::nanometer)
{}

MultiLayer* MagneticRotationBuilder::buildSample() const
{
    MultiLayer* multi_layer = new MultiLayer();

    kvector_t substr_field = kvector_t(0.0, 1e6, 0.0);
    kvector_t particle_field(1e6, 0.0, 0.0);
    Material air_material = HomogeneousMaterial("Air", 0.0, 0.0);
    Material substrate_material = HomogeneousMaterial("Substrate", 7e-6, 2e-8, substr_field);
    Material particle_material = HomogeneousMaterial("MagParticle", 6e-4, 2e-8, particle_field);

    ParticleLayout particle_layout;
    kvector_t position(0.0, 0.0, -10.0*Units::nanometer);
    FormFactorFullSphere ff_sphere(m_sphere_radius);
    Particle particle(particle_material, ff_sphere);
    RotationZ rot_z(90*Units::deg);
    particle_layout.addParticle(particle, 1.0, position, rot_z);

    Layer air_layer(air_material);
    Layer substrate_layer(substrate_material);
    substrate_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}
