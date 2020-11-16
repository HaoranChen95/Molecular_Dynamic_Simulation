#ifndef LATTICE_HPP_
#define LATTICE_HPP_

#include <random>
#include <list>

//#include "partical.hpp"
#include "MDParameter.hpp"
//#include "MDSimulation.hpp"
#include "velocity_verlet.hpp"

struct Particle{
	Vec q;
	Vec p;
	Vec f0;
	Vec f1;
};

std::list<Particle> init_lattice(const MDParameter parm);

Vec sum_force(const MDParameter parm, const Particle part, const std::list<Particle> p_l);

#endif