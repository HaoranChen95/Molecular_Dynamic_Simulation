#ifndef LATTICE_HPP_
#define LATTICE_HPP_

#include <random>
#include <list>

#include "partical.hpp"
#include "MDParameter.hpp"
#include "MDSimulation.hpp"

void initial_lattice(ParticleList *p_l, const MDParameter parm);

void init_lattice(std::list<Particle>& p_l, const MDParameter parm);

#endif