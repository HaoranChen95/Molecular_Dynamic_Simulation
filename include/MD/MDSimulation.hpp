#ifndef MDSIMULATION_HPP_
#define MDSIMULATION_HPP_

#include "velocity_verlet.hpp"
#include "write_data.hpp"

void MD_Simulation(const MDParameter parm, ParticlePtrList p_l);
double kin_energy(const MDParameter parm, const ParticlePtrList p_l);
double pot_energy(const MDParameter parm, const ParticleCPtrLL p_neighbor_ll);

#endif