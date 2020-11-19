#ifndef NEIGHBOR_HPP_
#define NEIGHBOR_HPP_

#include "lattice.hpp"
#include "periodic_boundary.hpp"

std::forward_list<std::forward_list<const Particle*>> neighbor(const MDParameter parm, const ParticleList p_l);

#endif