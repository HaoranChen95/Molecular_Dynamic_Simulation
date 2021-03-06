#ifndef PERIODIC_BOUNDARY_HPP_
#define PERIODIC_BOUNDARY_HPP_

#include "MDParameter.hpp"
#include "additional.hpp"

Vec periodic_vector(const MDParameter parm, const Vec q_a, const Vec q_b);
Vec periodic_coordinate(const MDParameter parm, const Vec q);

#endif