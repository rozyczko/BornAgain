// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Samples/src/ParticleLayout.cpp
//! @brief     Implements class ParticleLayout.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ParticleLayout.h"
#include "InterferenceFunctionNone.h"
#include "DecouplingApproximationStrategy.h"
#include "InterferenceFunctionRadialParaCrystal.h"
#include "SizeSpacingCorrelationApproximationStrategy.h"
#include "MessageService.h"
#include "ParticleDistribution.h"

#include <iomanip>


ParticleLayout::ParticleLayout()
{
    setName("ParticleLayout");
}

ParticleLayout::ParticleLayout(const IAbstractParticle& particle, double abundance)
{
    setName("ParticleLayout");
    addParticle(particle, abundance);
}

ParticleLayout::~ParticleLayout()
{
}

ParticleLayout* ParticleLayout::clone() const
{
    ParticleLayout *p_new = new ParticleLayout();
    p_new->setName(getName());

    for (size_t i=0; i<m_particles.size(); ++i)
        p_new->addAndRegisterParticleInfo(m_particles[i]->clone());

    for (size_t i=0; i<m_interference_functions.size(); ++i)
        p_new->addAndRegisterInterferenceFunction(
            m_interference_functions[i]->clone());

    p_new->setTotalParticleSurfaceDensity(getTotalParticleSurfaceDensity());
    p_new->setApproximation(getApproximation());

    return p_new;
}

ParticleLayout* ParticleLayout::cloneInvertB() const
{
    ParticleLayout *p_new = new ParticleLayout();
    p_new->setName(getName() + "_inv");

    for (size_t i=0; i<m_particles.size(); ++i)
        p_new->addAndRegisterParticleInfo(m_particles[i]->cloneInvertB());

    for (size_t i=0; i<m_interference_functions.size(); ++i)
        p_new->addAndRegisterInterferenceFunction(
            m_interference_functions[i]->clone());

    p_new->setTotalParticleSurfaceDensity(getTotalParticleSurfaceDensity());
    p_new->setApproximation(getApproximation());

    return p_new;
}

void ParticleLayout::addParticle(const IAbstractParticle& particle, double abundance)
{
    addAndRegisterParticleInfo(new ParticleInfo(particle, abundance));
}

void ParticleLayout::addParticle(const IParticle &particle, double abundance,
                                 const kvector_t &position)
{
    boost::scoped_ptr<IParticle> P_particle_clone(particle.clone());
    if(position != kvector_t(0,0,0)) {
        P_particle_clone->applyTranslation(position);
    }
    addAndRegisterParticleInfo(new ParticleInfo(*P_particle_clone, abundance));
}

void ParticleLayout::addParticle(const IParticle &particle, double abundance,
                                 const kvector_t &position, const IRotation& rotation)
{
    boost::scoped_ptr<IParticle> P_particle_clone(particle.clone());
    if(!rotation.isIdentity()) {
        P_particle_clone->applyRotation(rotation);
    }
    if(position != kvector_t(0,0,0)) {
        P_particle_clone->applyTranslation(position);
    }
    addAndRegisterParticleInfo(new ParticleInfo(*P_particle_clone, abundance));
}

//! Returns particle info
const IAbstractParticle* ParticleLayout::getParticle(size_t index) const
{
    if (index<m_particles.size())
        return m_particles[index]->getParticle();
    throw OutOfBoundsException(
        "ParticleLayout::getParticle() -> "
        "Error! Not so many particles in this decoration.");
}

void ParticleLayout::getParticleInfos(SafePointerVector<const IParticle>& particle_vector,
                                      std::vector<double>& abundance_vector) const
{
    particle_vector.clear();
    abundance_vector.clear();
    for (SafePointerVector<ParticleInfo>::const_iterator it = m_particles.begin();
         it != m_particles.end(); ++it) {
        const ParticleInfo *p_info = (*it);
        const ParticleDistribution *p_part_distr
            = dynamic_cast<const ParticleDistribution *>(p_info->getParticle());
        const IParticle *p_iparticle = dynamic_cast<const IParticle *>(p_info->getParticle());
        if (p_part_distr) {
            std::vector<const IParticle*> generated_particles;
            std::vector<double> abundances;
            p_part_distr->generateParticleInfos(generated_particles, abundances, p_info->getAbundance());
            for (size_t i = 0; i < generated_particles.size(); ++i) {
                particle_vector.push_back(generated_particles[i]);
                abundance_vector.push_back(abundances[i]);
            }
        } else if (p_iparticle) {
            particle_vector.push_back(p_iparticle->clone());
            abundance_vector.push_back(p_info->getAbundance());
        }
    }
    return;
}

double ParticleLayout::getAbundanceOfParticle(size_t index) const
{
    return m_particles[index]->getAbundance();
}

//! Adds interference functions
void ParticleLayout::addInterferenceFunction(
    IInterferenceFunction* p_interference_function)
{
    addAndRegisterInterferenceFunction(p_interference_function);
}

void ParticleLayout::addInterferenceFunction(
    const IInterferenceFunction& interference_function)
{
    addAndRegisterInterferenceFunction(interference_function.clone());
}

const IInterferenceFunction* ParticleLayout::getInterferenceFunction(
    size_t index) const
{
    if (index<m_interference_functions.size())
        return m_interference_functions[index];
    throw OutOfBoundsException(
        "ParticleLayout::getInterferenceFunction() ->"
                "Not so many interference functions in this decoration.");
}

//! Adds particle information with simultaneous registration in parent class.
void ParticleLayout::addAndRegisterParticleInfo(
    ParticleInfo *child)
{
    m_particles.push_back(child);
    registerChild(child);
}

//! Adds interference function with simultaneous registration in parent class.
void ParticleLayout::addAndRegisterInterferenceFunction(
    IInterferenceFunction *child)
{
    m_interference_functions.push_back(child);
    registerChild(child);
}

void ParticleLayout::print(std::ostream& ostr) const
{
    ILayout::print(ostr);
    ostr << "-->ParticleLayout<" << this << ">{\n";
    for( size_t i=0; i<m_particles.size(); ++i )
        ostr << "      - particle " << std::left << std::setw(2) << i << " { "
             << *(m_particles[i]) << "}\n";
    ostr << "}";
}

