// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Samples/inc/ParticleInfo.h
//! @brief     Defines class ParticleInfo.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef PARTICLEINFO_H
#define PARTICLEINFO_H

#include "ICompositeSample.h"
#include "IParticle.h"

//! @class ParticleInfo
//! @ingroup samples
//! @brief Holds additional information about particle.
//!
//! Used in ParticleLayout

class BA_CORE_API_ ParticleInfo : public ICompositeSample
{
public:
    ParticleInfo(const IParticle& p_particle,
                 double depth=0.0, double abundance=1.0);
    ParticleInfo(const IParticle& p_particle,
                 kvector_t position, double abundance=1.0);

    virtual ~ParticleInfo() {}

    virtual ParticleInfo *clone() const;

    //! Returns a clone with inverted magnetic fields
    virtual ParticleInfo *cloneInvertB() const;

    //! calls the ISampleVisitor's visit method
    virtual void accept(ISampleVisitor *visitor) const { visitor->visit(this); }

    //! Returns particle.
    const IParticle *getParticle() const { return mP_particle.get(); }

    //! Returns depth.
    double getDepth() const { return m_depth; }

    //! Sets depth.
    void setDepth(double depth) { m_depth = depth; }

    //! Returns particle position, including depth.
    kvector_t getPosition() const { return kvector_t(m_x, m_y, -m_depth); }

    //! Sets particle position, including depth.
    void setPosition(kvector_t position);

    //! Returns abundance.
    double getAbundance() const { return m_abundance; }

    //! Sets abundance.
    void setAbundance(double abundance) { m_abundance = abundance; }

    //! Sets the ambient material
    void setAmbientMaterial(const IMaterial *p_material) {
        mP_particle->setAmbientMaterial(p_material);
    }

protected:
    virtual void init_parameters();

    virtual void print(std::ostream& ostr) const;

    std::auto_ptr<IParticle> mP_particle;
    double m_x;
    double m_y;
    double m_depth;
    double m_abundance;
};

#endif /* PARTICLEINFO_H */


