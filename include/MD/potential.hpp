#ifndef POTENTIAL_HPP_
#define POTENTIAL_HPP_

#include "MDParameter.hpp"
#include "periodic_boundary.hpp"

double LJ_Potential(const MDParameter para, const double r);
Vec LJ_Force(const MDParameter parm, const Vec q_a, const Vec q_b);

#endif