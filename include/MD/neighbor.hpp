#ifndef NEIGHBOR_HPP_
#define NEIGHBOR_HPP_

#include "lattice.hpp"

std::list<std::list<std::list<Particle>::const_iterator>> neighbor(const MDParameter parm, const std::list<Particle> p_l);

#endif