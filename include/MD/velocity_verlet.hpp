#ifndef VELOCITY_VERLET_HPP_
#define VELOCITY_VERLET_HPP_

#include "potential.hpp"
#include "lattice.hpp"


Vec velocity_verlet_x(const MDParameter parm, const Particle part);
Vec velocity_verlet_v(const MDParameter parm, const Particle part);
Vec sum_force(const MDParameter parm, const Particle part, const std::forward_list<Particle> p_l);

#endif