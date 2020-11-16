#ifndef NEIGHBOR_HPP_
#define NEIGHBOR_HPP_

#include "lattice.hpp"

std::list<std::list<Particle*>> neighbor(const MDParameter parm, const std::list<Particle> p_l);

#endif