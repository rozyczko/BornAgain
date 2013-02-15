#ifndef EXPERIMENT_H_
#define EXPERIMENT_H_
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   Experiment.h
//! @brief  Definition of Experiment class
//! @author Scientific Computing Group at FRM II
//! @date   20.06.2012

#include "ISample.h"
#include "ISampleBuilder.h"
#include "OutputData.h"
#include "Instrument.h"
#include "SimulationParameters.h"

class ProgramOptions;

class Experiment : public IParameterized, public ICloneable
{
public:
    Experiment();
    Experiment(const ProgramOptions *p_options);
    Experiment(const ISample &p_sample, const ProgramOptions *p_options=0);
    Experiment(const ISampleBuilder *p_sample_builder, const ProgramOptions *p_options=0);
    ~Experiment() {delete mp_sample;}

    //! clone method fot the experiment
    Experiment *clone() const;

    //! put into a clean state for running a simulation
    void prepareSimulation();

    //! run a simulation with the current parameter settings
    void runExperiment();

    //! calculate intensity for a single detector element
    void runExperimentElement(size_t index);

    //! normalize the detector counts
    void normalize();

    //! set the sample to be tested
    void setSample(const ISample &p_sample);

    //! get the sample
    ISample *getSample() { return mp_sample; }
    const ISample *getSample() const { return mp_sample; }

    //! set the sample builder
    void setSampleBuilder(const ISampleBuilder *p_sample_builder);

    //! get data structure that contains the intensity map on the detector for all scan parameters
    OutputData<double>* getOutputDataClone() const;

    const OutputData<double>* getOutputData() const;

    //! get the instrument containing beam and detector information
    Instrument &getInstrument() { return m_instrument; }
    const Instrument &getInstrument() const { return m_instrument; }

    //! set beam parameters from here (forwarded to Instrument)
    void setBeamParameters(double lambda, double alpha_i, double phi_i);

    //! set beam intensity from here (forwarded to Instrument)
    void setBeamIntensity(double intensity);

    //! set detector parameters using axes of output data
    void setDetectorParameters(const OutputData<double > &output_data);

    //! set detector parameters using angle ranges
    void setDetectorParameters(size_t n_phi, double phi_f_min, double phi_f_max,
            size_t n_alpha, double alpha_f_min, double alpha_f_max, bool isgisaxs_style=false);

    //! set detector parameters using parameter object
    void setDetectorParameters(const DetectorParameters &params);
    //! get simulation parameters
    SimulationParameters getSimulationParameters() const { return m_sim_params; }

    //! define resolution function for detector
    void setDetectorResolutionFunction(IResolutionFunction2D *p_resolution_function);

    //! set simulation parameters
    void setSimulationParameters(const SimulationParameters &sim_params) {
        m_sim_params = sim_params;
    }

    //! set the program options
    void setProgramOptions(ProgramOptions *p_options) { mp_options = p_options; }

    //! add parameters from local pool to external pool and call recursion over direct children
    std::string addParametersToExternalPool(std::string path, ParameterPool *external_pool, int copy_number=-1) const;

    //! apply smearing of intensity due to tilting of z-axis (DEPRECATED)
    void smearIntensityFromZAxisTilting();
protected:
    Experiment(const Experiment &other);

    //! initialize pool parameters, i.e. register some of class members for later access via parameter pool
    void init_parameters();

    //! Default implementation only adds the detector axes
    void updateIntensityMapAxes();

    //! Update the sample by calling the sample builder, if present
    void updateSample();

    ISample *mp_sample;
    const ISampleBuilder *mp_sample_builder;
    Instrument m_instrument;
    OutputData<double> m_intensity_map;
    bool m_is_normalized;
    const ProgramOptions *mp_options;
    SimulationParameters m_sim_params;
    //TODO: move to private when Experiment is removed
    double deltaAlpha(double alpha, double zeta) const;
    double deltaPhi(double alpha, double phi, double zeta) const;
    void createZetaAndProbVectors(std::vector<double> &zetas, std::vector<double> &probs, size_t nbr_zetas, double zeta_sigma) const;
    void addToIntensityMap(double alpha, double phi, double value);
};





#endif /* EXPERIMENT_H_ */
