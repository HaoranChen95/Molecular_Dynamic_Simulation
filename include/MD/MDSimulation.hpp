#ifndef MDSIMULATION_HPP_
#define MDSIMULATION_HPP_

#include "MDParameter.hpp"
#include "partical.hpp"
#include "periodic_boundary.hpp"
#include "velocity_verlet.hpp"
#include "write_data.hpp"

#include "additional.hpp"
#include <list>

void MD_Simulation(ParticleList *p_l, MDParameter parm);

// void MD_Simulation_Plus(list<Particle> *p_l, const MDParameter parm);

#endif