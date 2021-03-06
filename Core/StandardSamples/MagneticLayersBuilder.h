// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/StandardSamples/MagneticLayersBuilder.h
//! @brief    Defines class to build samples with magnetic layers
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef MAGNETICLAYERSBUILDER_H
#define MAGNETICLAYERSBUILDER_H

#include "IMultiLayerBuilder.h"

class ISample;

//! Builds sample: spheres in substrate layer with a zero magnetic field.
//! @ingroup standard_samples

class BA_CORE_API_ MagneticSubstrateZeroFieldBuilder : public IMultiLayerBuilder
{
public:
    MagneticSubstrateZeroFieldBuilder();
    MultiLayer* buildSample() const;

private:
    double m_sphere_radius;
};

//! Builds sample: rotated magnetic spheres in substrate layer with a unit magnetic field.
//! @ingroup standard_samples

class BA_CORE_API_ MagneticRotationBuilder : public IMultiLayerBuilder
{
public:
    MagneticRotationBuilder();
    MultiLayer* buildSample() const;

private:
    double m_sphere_radius;
};

#endif // MAGNETICLAYERSBUILDER_H
