// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Samples/inc/HomogeneousMaterial.h
//! @brief     Defines and fully implements class HomogeneousMaterial.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef HOMOGENEOUSMATERIAL_H
#define HOMOGENEOUSMATERIAL_H

#include "IMaterial.h"
#include "Types.h"

//! A homogeneous material with a refractive index.

class HomogeneousMaterial : public IMaterial
{
 public:
    //! Constructs a material with _name_ and _refractive_index_.
    HomogeneousMaterial(const std::string& name,
                        const complex_t& refractive_index)
        : IMaterial(name), m_refractive_index(refractive_index) {}

    //! Constructs a material with _name_ and refractive_index parameters
    //! delta and beta (n = 1 - delta + i*beta).
    HomogeneousMaterial(const std::string& name,
                        double refractive_index_delta,
                        double refractive_index_beta)
        : IMaterial(name),
        m_refractive_index(complex_t(1.0-refractive_index_delta,
                                     refractive_index_beta)) {}

    virtual ~HomogeneousMaterial() {}

    //! Return refractive index.
    complex_t getRefractiveIndex() const { return m_refractive_index; }

    //! Set refractive index.
    void setRefractiveIndex(const complex_t &refractive_index)
    { m_refractive_index = refractive_index; }

 protected:
    virtual void print(std::ostream& ostr) const
    {
        ostr  << "HomMat:" << getName() << "<" << this << ">{ " <<
                 "R=" << m_refractive_index << "}";
    }

    complex_t m_refractive_index; //!< complex index of refraction
};

#endif // HOMOGENEOUSMATERIAL_H


