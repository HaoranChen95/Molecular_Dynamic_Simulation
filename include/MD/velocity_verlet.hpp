#ifndef VELOCITY_VERLET_HPP_
#define VELOCITY_VERLET_HPP_

#include "partical.hpp"
#include "MDParameter.hpp"
#include "periodic_boundary.hpp"
#include "potential.hpp"

void sum_force(ParticleList p_l, double (*force)(const MDParameter parm, const double r), MDParameter parm);
void velocity_verlet_x(ParticleList *p_l, const MDParameter parm);
void velocity_verlet_v(ParticleList *p_l, const MDParameter parm);

#endif