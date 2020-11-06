#ifndef POTENTIAL_HPP_
#define POTENTIAL_HPP_

#include "MDParameter.hpp"

double LJ_Potential(const MDParameter para, const double r);
double LJ_Force(const MDParameter para, const double r);

#endif