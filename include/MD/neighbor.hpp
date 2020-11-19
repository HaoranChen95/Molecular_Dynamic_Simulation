#ifndef NEIGHBOR_HPP_
#define NEIGHBOR_HPP_

#include "lattice.hpp"

std::forward_list<std::forward_list<std::forward_list<Particle>::const_iterator>> neighbor(const MDParameter parm, const std::forward_list<Particle> p_l);

#endif