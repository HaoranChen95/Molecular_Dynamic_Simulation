#ifndef LATTICE_HPP_
#define LATTICE_HPP_

#include <random>
#include <forward_list>

#include "MDParameter.hpp"
#include "potential.hpp"

struct Particle{
	Vec x;
	Vec v;
	Vec f0;
	Vec f1;
};

std::forward_list<Particle> init_lattice(const MDParameter parm);

Vec sum_force(const MDParameter parm, const Particle part, const std::forward_list<Particle> p_l); //TODO change the partical list to part_l_iter

#endif