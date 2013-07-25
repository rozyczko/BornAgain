// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Algorithms/src/DWBASimulation.cpp
//! @brief     Implements class DWBASimulation.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "DWBASimulation.h"


void DWBASimulation::init(const Simulation& simulation)
{
    if (mp_simulation !=& simulation) {
        delete mp_simulation;
        mp_simulation = simulation.clone();
    }
    m_dwba_intensity.clear();
    Detector detector = simulation.getInstrument().getDetector();
    size_t detector_dimension = detector.getDimension();
    for (size_t dim=0; dim<detector_dimension; ++dim) {
        m_dwba_intensity.addAxis(detector.getAxis(dim));
    }
    if (simulation.getOutputData()->getMask()) {
        m_dwba_intensity.setMask(*simulation.getOutputData()->getMask());
    }
    Beam beam = simulation.getInstrument().getBeam();
    m_ki = beam.getCentralK();
    kvector_t ki_real(m_ki.x().real(), m_ki.y().real(), m_ki.z().real());
    m_alpha_i = std::asin(ki_real.z()/ki_real.mag());
    m_sim_params = simulation.getSimulationParameters();
}

DWBASimulation *DWBASimulation::clone() const
{
    DWBASimulation *p_result = new DWBASimulation();
    p_result->m_dwba_intensity.copyFrom(m_dwba_intensity);
    p_result->m_ki = m_ki;
    p_result->m_alpha_i = m_alpha_i;
    p_result->m_thread_info = m_thread_info;
    if (mp_simulation)
        p_result->mp_simulation = mp_simulation->clone();
    return p_result;
}

double DWBASimulation::getWaveLength() const
{
    kvector_t real_ki(m_ki.x().real(), m_ki.y().real(), m_ki.z().real());
    return 2*M_PI/real_ki.mag();
}


