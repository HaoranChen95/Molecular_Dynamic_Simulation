#ifndef VELOCITY_VERLET_HPP_
#define VELOCITY_VERLET_HPP_

#include <list>

#include "potential.hpp"
#include "lattice.hpp"

typedef std::list<std::forward_list<const Particle*>> ParticleCPLL;
typedef std::forward_list<const Particle*> ParticleCPL;

Vec velocity_verlet_x(const MDParameter parm, const Particle part);
Vec velocity_verlet_v(const MDParameter parm, const Particle part);
Vec sum_force(const MDParameter parm, const Particle part, const ParticleCPL p_l);
bool is_neighbor(const MDParameter parm, const Particle p_a, const Particle p_b);
ParticleCPLL neighbors_list(const MDParameter parm, const ParticleList p_l);
#endif