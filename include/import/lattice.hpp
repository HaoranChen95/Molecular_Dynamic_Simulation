#ifndef LATTICE_HPP_
#define LATTICE_HPP_

#include <random>
#include <forward_list>
#include <memory>

#include "MDParameter.hpp"

struct Particle{
	Vec x;
	Vec v;
	Vec f0;
	Vec f1;
};

typedef std::shared_ptr <Particle> ParticlePtr;
typedef std::shared_ptr <const Particle> ParticleCPtr;
typedef std::forward_list<std::shared_ptr <Particle>> ParticlePtrList;
typedef std::forward_list<std::shared_ptr <const Particle>> ParticleCPtrL;
typedef std::list<std::forward_list<std::shared_ptr <const Particle>>> ParticleCPtrLL;

ParticlePtrList init_lattice(const MDParameter parm);

#endif