#ifndef LATTICE_HPP_
#define LATTICE_HPP_

#include <random>
#include <list>

#include "partical.hpp"
#include "MDParameter.hpp"
#include "MDSimulation.hpp"

std::list<Particle> init_lattice(const MDParameter parm);

#endif