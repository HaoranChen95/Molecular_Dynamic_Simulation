#ifndef VELOCITY_VERLET_HPP_
#define VELOCITY_VERLET_HPP_

#include "MDParameter.hpp"
#include "lattice.hpp"


Vec velocity_verlet_x(const MDParameter parm, const Particle part);
Vec velocity_verlet_v(const MDParameter parm, const Particle part);

#endif