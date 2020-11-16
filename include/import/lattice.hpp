#ifndef LATTICE_HPP_
#define LATTICE_HPP_

#include <random>
#include <list>

#include "partical.hpp"
#include "MDParameter.hpp"
#include "MDSimulation.hpp"

void initial_lattice(ParticleList *p_l, const MDParameter parm);

std::list<Particle> init_lattice(const MDParameter parm);

#endif