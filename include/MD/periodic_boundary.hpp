#ifndef PERIODIC_BOUNDARY_HPP_
#define PERIODIC_BOUNDARY_HPP_

#include "additional.hpp"
#include "MDParameter.hpp"

Vec periodic_vector(const MDParameter parm, const Vec q_a, const Vec q_b);
Vec periodic_coordinate(const MDParameter parm, const Vec q);

#endif