#ifndef LATTICE_HPP_
#define LATTICE_HPP_

#include <random>
#include <forward_list>

#include "MDParameter.hpp"

struct Particle{
	Vec x;
	Vec v;
	Vec f0;
	Vec f1;
};

typedef std::forward_list<Particle> ParticleList;

ParticleList init_lattice(const MDParameter parm);

#endif