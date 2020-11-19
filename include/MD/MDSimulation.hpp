#ifndef MDSIMULATION_HPP_
#define MDSIMULATION_HPP_

#include "velocity_verlet.hpp"
#include "neighbor.hpp"
#include "write_data.hpp"

void MD_Simulation(const MDParameter parm, ParticleList p_l);
double kin_energy(const MDParameter parm, const ParticleList p_l);
double pot_energy(std::forward_list<std::forward_list<ParticleList::const_iterator>> p_n);

#endif