#ifndef POTENTIAL_HPP_
#define POTENTIAL_HPP_

#include "periodic_boundary.hpp"

double Cut_LJ_Potential(const MDParameter parm, const Vec q_a, const Vec q_b);
Vec Cut_LJ_Force(const MDParameter parm, const Vec q_a, const Vec q_b);

#endif