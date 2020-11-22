#ifndef MDSIMULATION_HPP_
#define MDSIMULATION_HPP_

#include "velocity_verlet.hpp"
#include "neighbor.hpp"
#include "write_data.hpp"

void MD_Simulation(const MDParameter parm, ParticleList p_l);
double kin_energy(const MDParameter parm, const ParticleList p_l);
double pot_energy(const MDParameter parm, const ParticleList p_l);

#endif