// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Computation/MainComputation.h
//! @brief     Defines class MainComputation.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef MULTILAYERCOMPUTATION_H
#define MULTILAYERCOMPUTATION_H

#include "IComputation.h"
#include "ComputationOutcome.h"
#include "Complex.h"
#include <map>

class DecoratedLayerComputation;
class MultiLayer;
class RoughMultiLayerComputation;

//! Performs a DWBA calculation with given sample and simulation parameters
//! @ingroup algorithms_internal

class BA_CORE_API_ MainComputation : public IComputation
{
public:
    MainComputation(const MultiLayer* p_multi_layer);
    ~MainComputation() final;

    void init(
        const SimulationOptions& options,
        const Simulation& simulation,
        std::vector<SimulationElement>::iterator begin_it,
        std::vector<SimulationElement>::iterator end_it) final;

    void run() final;

    bool isCompleted() const { return m_outcome.isCompleted(); }
    std::string getRunMessage() const { return m_outcome.getRunMessage(); }

private:
    void runProtected() final;

    //! calculates intensity map for samples with magnetization
    void collectRTCoefficientsScalar();
    void collectRTCoefficientsMatrix();

    std::vector<std::vector<DecoratedLayerComputation*>> m_layer_computation;
    MultiLayer* mp_multi_layer;
    RoughMultiLayerComputation* mp_roughness_computation;
    ComputationOutcome m_outcome;
};

#endif // MULTILAYERCOMPUTATION_H
