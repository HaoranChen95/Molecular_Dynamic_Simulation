#ifndef VELOCITY_VERLET_HPP_
#define VELOCITY_VERLET_HPP_

#include <list>

#include "potential.hpp"
#include "lattice.hpp"

Vec velocity_verlet_x(const MDParameter parm, const Particle part);
Vec velocity_verlet_v(const MDParameter parm, const Particle part);
Vec sum_force(const MDParameter parm, const Particle part, const ParticleCPtrL p_l);
bool is_neighbor(const MDParameter parm, const Particle p_a, const Particle p_b);
ParticleCPtrLL neighbors_list(const MDParameter parm, const ParticlePtrList p_l);

ParticleCPtrLL all_particle_PtrLL(const MDParameter parm, const ParticlePtrList p_l);

#endif