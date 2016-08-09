// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Particle/FormFactorWeighted.h
//! @brief     Defines class FormFactorWeighted.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORWEIGHTED_H
#define FORMFACTORWEIGHTED_H

#include "IFormFactor.h"

//! @class FormFactorWeighted
//! @ingroup formfactors_internal
//! @brief Coherent sum of different form factors with different weights.
//! Acts on scalar form factors.

class BA_CORE_API_ FormFactorWeighted : public IFormFactor
{
public:
    FormFactorWeighted();
    virtual ~FormFactorWeighted();

    virtual FormFactorWeighted* clone() const;

    virtual void accept(ISampleVisitor* visitor) const;

    virtual double getRadialExtension() const;

    void addFormFactor(const IFormFactor& form_factor, double weight=1.0);

    virtual void setAmbientMaterial(const IMaterial& material);

    virtual complex_t evaluate(const WavevectorInfo& wavevectors) const;

#ifndef SWIG
    //! Calculates and returns a polarized form factor calculation in DWBA
    virtual Eigen::Matrix2cd evaluatePol(const WavevectorInfo& wavevectors) const;
#endif

protected:
    std::vector<IFormFactor*> m_form_factors;
    std::vector<double> m_weights;
};

#endif // FORMFACTORWEIGHTED_H