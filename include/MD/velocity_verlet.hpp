#ifndef VELOCITY_VERLET_HPP_
#define VELOCITY_VERLET_HPP_

#include <list>

#include "lattice.hpp"
#include "potential.hpp"

Vec velocity_verlet_x(const MDParameter parm, const Particle part);
Vec velocity_verlet_v(const MDParameter parm, const Particle part);
Vec sum_force(const MDParameter parm, const Particle part,
              const ParticlePtrList p_l);
bool is_neighbor(const MDParameter parm, const Particle p_a,
                 const Particle p_b);
ParticlePtrLL neighbors_list(const MDParameter parm, const ParticlePtrList p_l);
ParticlePtrLL neighbors_list_forward(const MDParameter parm,
                                     const ParticlePtrList p_l);

ParticlePtrLL all_particle_PtrLL(const MDParameter parm,
                                 const ParticlePtrList p_l);
void write_neighbor_list(const MDParameter parm, const ParticlePtrLL nb_pll,
                         const std::string& path = "neighbor_list");

#endif