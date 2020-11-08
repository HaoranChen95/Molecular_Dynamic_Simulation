#ifndef PERIODIC_BOUNDARY_HPP_
#define PERIODIC_BOUNDARY_HPP_

#include "additional.hpp"
#include "MDParameter.hpp"

Vec periodic_force(const Vec x_a, const Vec x_b, double (*force)(const MDParameter parm, const double r), const MDParameter parm);
Vec periodic_boundary(Vec x, const MDParameter parm);

#endif