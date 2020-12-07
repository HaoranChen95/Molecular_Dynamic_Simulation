#ifndef LATTICE_HPP_
#define LATTICE_HPP_

#include <forward_list>
#include <memory>
#include <random>

#include "MDParameter.hpp"

struct Particle {
  Vec x{Vec::Zero(3)};
  Vec v{Vec::Zero(3)};
  Vec f0{Vec::Zero(3)};
  Vec f1{Vec::Zero(3)};
};

typedef std::shared_ptr<Particle> ParticlePtr;
typedef std::shared_ptr<const Particle> ParticleCPtr;
typedef std::forward_list<std::shared_ptr<Particle>> ParticlePtrList;
typedef std::forward_list<std::shared_ptr<const Particle>> ParticleCPtrL;
typedef std::list<std::forward_list<std::shared_ptr<Particle>>> ParticlePtrLL;
// typedef std::list<std::forward_list<std::shared_ptr <const Particle>>>
// ParticleCPtrLL;

ParticlePtrList init_lattice(const MDParameter parm);

void write_ParticleList(const ParticlePtrList p_l,
                        const std::string& path = "all_Particles",
                        const std::string& suffix = ".txt");
ParticlePtrList read_ParticleList(const std::string& path = "all_Particles",
                                  const std::string& suffix = ".txt");

#endif