// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Samples/src/ParticleComposition.cpp
//! @brief     Implements class ParticleComposition.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ParticleComposition.h"
#include "FormFactors.h"
#include "Materials.h"
#include <boost/scoped_ptr.hpp>

ParticleComposition::ParticleComposition()
{
    setName("ParticleComposition");
}

ParticleComposition::ParticleComposition(const IParticle& particle)
{
    setName("ParticleComposition");
    addParticle( particle, kvector_t(0.0, 0.0, 0.0) );
}

ParticleComposition::ParticleComposition(const IParticle &particle, kvector_t position)
{
    setName("ParticleComposition");
    addParticle(particle, position);
}

ParticleComposition::ParticleComposition(const IParticle& particle,
        std::vector<kvector_t> positions)
{
    setName("ParticleComposition");
    addParticles(particle, positions);
}

ParticleComposition::~ParticleComposition()
{
    for (size_t index=0; index<m_particles.size(); ++index) {
        delete m_particles[index];
    }
}

ParticleComposition* ParticleComposition::clone() const
{
    ParticleComposition *p_new = new ParticleComposition();
    for (size_t index=0; index<m_particles.size(); ++index) {
        p_new->addParticle(*m_particles[index]);
    }
    p_new->setName(getName());
    p_new->setAmbientMaterial(*getAmbientMaterial());
    if (mP_rotation.get()) {
        p_new->mP_rotation.reset(mP_rotation->clone());
    }
    return p_new;
}

ParticleComposition* ParticleComposition::cloneInvertB() const
{
    ParticleComposition *p_new = new ParticleComposition();
    for (size_t index=0; index<m_particles.size(); ++index) {
        p_new->addParticlePointer(m_particles[index]->cloneInvertB());
    }
    p_new->setName(getName() + "_inv");

    if(getAmbientMaterial()) {
        p_new->setAmbientMaterial(*Materials::createInvertedMaterial(getAmbientMaterial()));
    }
    if (mP_rotation.get()) {
        p_new->mP_rotation.reset(mP_rotation->clone());
    }

    return p_new;
}

void ParticleComposition::addParticle(const IParticle &particle)
{
    IParticle *np = particle.clone();
    registerChild(np);
    m_particles.push_back(np);
}

void ParticleComposition::addParticle(const IParticle &particle, kvector_t position)
{
    IParticle *np = particle.clone();
    np->setPosition(position);
    registerChild(np);
    m_particles.push_back(np);
}

void ParticleComposition::addParticles(const IParticle& particle,
        std::vector<kvector_t > positions)
{
    for (size_t i=0; i<positions.size(); ++i) {
        addParticle(particle, positions[i]);
    }
}

void ParticleComposition::setAmbientMaterial(const IMaterial& material)
{
    for (size_t index=0; index<m_particles.size(); ++index) {
        m_particles[index]->setAmbientMaterial(material);
    }
}

const IMaterial *ParticleComposition::getAmbientMaterial() const
{
    if (m_particles.size()==0) return 0;
    return m_particles[0]->getAmbientMaterial();
}

IFormFactor* ParticleComposition::createFormFactor(
        complex_t wavevector_scattering_factor) const
{
    FormFactorWeighted *p_ff = new FormFactorWeighted();
    for (size_t index=0; index<m_particles.size(); ++index) {
        boost::scoped_ptr<IFormFactor> P_particle_ff(
                m_particles[index]->createFormFactor(
                                      wavevector_scattering_factor));
        p_ff->addFormFactor(*P_particle_ff);
    }
    p_ff->setAmbientMaterial(*getAmbientMaterial());
    return p_ff;
}

void ParticleComposition::applyTransformationToSubParticles(const IRotation& rotation)
{
    for (std::vector<IParticle *>::iterator it = m_particles.begin();
            it != m_particles.end(); ++it)
    {
        (*it)->applyRotation(rotation);
    }
}

void ParticleComposition::addParticlePointer(IParticle* p_particle)
{
    registerChild(p_particle);
    m_particles.push_back(p_particle);
}

