#ifndef LATTICE_HPP_
#define LATTICE_HPP_

#include <memory>
#include <random>
#include <vector>

#include "periodic_boundary.hpp"

struct Particle {
  Vec x{Vec::Zero(3)};
  Vec v{Vec::Zero(3)};
  Vec f0{Vec::Zero(3)};
  Vec f1{Vec::Zero(3)};
};

typedef std::shared_ptr<Particle> ParticlePtr;
typedef std::shared_ptr<const Particle> ParticleCPtr;
typedef std::vector<std::shared_ptr<Particle>> ParticlePtrList;
typedef std::vector<std::shared_ptr<const Particle>> ParticleCPtrL;
typedef std::vector<std::vector<std::shared_ptr<Particle>>> ParticlePtrLL;
// typedef std::list<std::vector<std::shared_ptr <const Particle>>>
// ParticleCPtrLL;

ParticlePtrList init_lattice(const MDParameter parm);

void write_ParticleList(const MDParameter parm, const ParticlePtrList p_l,
                        const std::string& path = "all_Particles",
                        const std::string& suffix = ".txt");
ParticlePtrList read_ParticleList(const std::string& path = "all_Particles",
                                  const std::string& suffix = ".txt");

#endif