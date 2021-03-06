// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Shapes/SlicedFormFactorList.cpp
//! @brief     Defines class SlicedFormFactorList.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //


#include "SlicedFormFactorList.h"
#include "IParticle.h"
#include "MultiLayer.h"
#include "Rotations.h"
#include <utility>

namespace {
std::pair<size_t, size_t> LayerIndicesLimits(const IParticle& particle,
                                             const MultiLayer& multilayer,
                                             size_t ref_layer_index);
double ZDifference(const MultiLayer& multilayer, size_t layer_index, size_t ref_layer_index);
ZLimits LayerZLimits(const MultiLayer& multilayer, size_t layer_index);
void ScaleRegions(std::vector<HomogeneousRegion>& regions, double factor);
}

SlicedFormFactorList SlicedFormFactorList::CreateSlicedFormFactors(const IParticle& particle,
                                                                   const MultiLayer& multilayer,
                                                                   size_t ref_layer_index)
{
    SlicedFormFactorList result;
    auto particles = particle.decompose();
    for (auto p_particle : particles) {
        result.addParticle(*p_particle, multilayer, ref_layer_index);
    }
    return result;
}

void SlicedFormFactorList::addParticle(IParticle& particle,
                                       const MultiLayer& multilayer, size_t ref_layer_index)
{
    auto layer_indices = LayerIndicesLimits(particle, multilayer, ref_layer_index);
    bool single_layer = (layer_indices.first==layer_indices.second);
    for (size_t i=layer_indices.first; i<layer_indices.second+1; ++i)
    {
        kvector_t translation(0.0, 0.0, -ZDifference(multilayer, i, ref_layer_index));
        particle.translate(translation);
        // if particle is contained in this layer, set limits to infinite:
        ZLimits limits = single_layer ? ZLimits()
                                      : LayerZLimits(multilayer, i);
        auto sliced_particle = particle.createSlicedParticle(limits);
        m_ff_list.emplace_back(std::move(sliced_particle.mP_slicedff), i);
        if (multilayer.layerThickness(i)!=0.0)
            ScaleRegions(sliced_particle.m_regions, 1/multilayer.layerThickness(i));
        m_region_map[i].insert(m_region_map[i].end(), sliced_particle.m_regions.begin(),
                               sliced_particle.m_regions.end());
        ref_layer_index = i;  // particle now has coordinates relative to layer i
    }
}

size_t SlicedFormFactorList::size() const
{
    return m_ff_list.size();
}

std::pair<const IFormFactor*, size_t> SlicedFormFactorList::operator[](size_t index) const
{
    if (index >= size())
        throw std::out_of_range("SlicedFormFactorList::operator[] error: "
                                "index out of range");
    return { m_ff_list[index].first.get(), m_ff_list[index].second };
}

std::map<size_t, std::vector<HomogeneousRegion>> SlicedFormFactorList::regionMap() const
{
    return m_region_map;
}

namespace {
std::pair<size_t, size_t> LayerIndicesLimits(const IParticle& particle,
                                             const MultiLayer& multilayer,
                                             size_t ref_layer_index)
{
    double position_offset = multilayer.layerTopZ(ref_layer_index);
    auto bottomTopZ = particle.bottomTopZ();
    double zbottom = bottomTopZ.m_bottom;
    double ztop = bottomTopZ.m_top ;
    double eps = (ztop - zbottom)*1e-6;  // allow for relatively small crossing due to numerical
                                         // approximations (like rotation over 180 degrees)
    double zmax = ztop + position_offset - eps;
    double zmin = zbottom + position_offset + eps;
    size_t top_index = multilayer.topZToLayerIndex(zmax);
    size_t bottom_index = multilayer.bottomZToLayerIndex(zmin);
    if (top_index>bottom_index)  // happens for zero size particles
        top_index = bottom_index;
    return { top_index, bottom_index };
}

double ZDifference(const MultiLayer& multilayer, size_t layer_index, size_t ref_layer_index)
{
    return multilayer.layerTopZ(layer_index) - multilayer.layerTopZ(ref_layer_index);
}

ZLimits LayerZLimits(const MultiLayer& multilayer, size_t layer_index)
{
    size_t N = multilayer.numberOfLayers();
    if (N<2)
        return ZLimits {};
    if (layer_index==0)
        return ZLimits( { false, 0 }, { true, 0} );
    if (layer_index==N-1)
        return ZLimits( { true, 0 }, { false, 0} );
    return ZLimits(-multilayer.layerThickness(layer_index), 0.0);
}

void ScaleRegions(std::vector<HomogeneousRegion>& regions, double factor)
{
    for (auto& region : regions)
        region.m_volume *= factor;
}
}

