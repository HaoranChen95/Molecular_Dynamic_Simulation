#ifndef MDSIMULATION_HPP_
#define MDSIMULATION_HPP_

#include "velocity_verlet.hpp"

void MD_Simulation(const MDParameter parm, ParticlePtrList p_l);
double kin_energy(const MDParameter parm, const ParticlePtrList p_l);
double pot_energy(const MDParameter parm, const ParticlePtrLL p_neighbor_ll);
double pot_energy_all(const MDParameter parm, const ParticlePtrList p_l);
double pot_energy_forward(const MDParameter parm,
                          const ParticlePtrLL p_neighbor_ll);
double mean_sqrt_trajectory(const MDParameter parm, const ParticlePtrList p_l);

void force_forward(const MDParameter parm, const ParticlePtrLL nb_ll);

#endif