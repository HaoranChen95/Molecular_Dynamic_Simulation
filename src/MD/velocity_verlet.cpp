#include "velocity_verlet.hpp"
using namespace std;

Vec velocity_verlet_x(const MDParameter parm, const Particle part) {
  return part.x + part.v * parm.time_step() +
         part.f0 / 2.0 / parm.m() * pow(parm.time_step(), 2.0);
}

Vec velocity_verlet_v(const MDParameter parm, const Particle part) {
  return part.v + (part.f0 + part.f1) / 2.0 / parm.m() * parm.time_step();
}

/**
 * @brief calculate the force at particle from the other particle const_iterator
 * list
 *
 * @param[in] parm
 * @param[in] part
 * @param[in] p_il
 * @return Vec
 */

Vec sum_force(const MDParameter parm, const Particle part,
              const ParticlePtrList p_pl) {
  Vec f{Vec::Zero(3)};
  for (ParticleCPtr i : p_pl) {
    f += Cut_LJ_Force(parm, part.x, (*i).x);
  }
  return f;
}

bool is_neighbor(const MDParameter parm, const Particle p_a,
                 const Particle p_b) {
  double r{periodic_vector(parm, p_a.x, p_b.x).norm()};
  return r < parm.neighbor() && r != 0;
}

ParticlePtrLL neighbors_list(const MDParameter parm,
                             const ParticlePtrList p_l) {
  ParticlePtrLL nb_pll;
  for (ParticlePtr p : p_l) {
    ParticlePtrList nb_pl{};
    for (ParticlePtr other_p : p_l) {
      if (is_neighbor(parm, *p, *other_p)) {
        nb_pl.push_front(other_p);
      }
    }
    nb_pl.push_front(p);
    nb_pll.push_back(nb_pl);
  }
  return nb_pll;
}

ParticlePtrLL neighbors_list_forward(const MDParameter parm,
                                     const ParticlePtrList p_l) {
  ParticlePtrLL nb_pll;

  ParticlePtrList::const_iterator p_l_it{p_l.cbegin()};
  ParticlePtrList::const_iterator other_p_l_it{};
  while (p_l_it != p_l.cend()) {
    other_p_l_it = p_l_it;
    ++other_p_l_it;
    ParticlePtrList nb_pl{};
    while (other_p_l_it != p_l.cend()) {
      if (is_neighbor(parm, **p_l_it, **other_p_l_it)) {
        nb_pl.push_front(*other_p_l_it);
      }
      ++other_p_l_it;
    }
    nb_pl.push_front(*p_l_it);
    nb_pll.push_back(nb_pl);
    ++p_l_it;
  }
  return nb_pll;
}

ParticlePtrLL all_particle_PtrLL(const ParticlePtrList p_l) {
  ParticlePtrLL nb_pll;

  ParticlePtrList::const_iterator p_l_it{p_l.cbegin()};
  ParticlePtrList::const_iterator other_p_l_it{};
  while (p_l_it != p_l.cend()) {
    other_p_l_it = p_l_it;
    ++other_p_l_it;
    ParticlePtrList nb_pl{};
    while (other_p_l_it != p_l.cend()) {
      nb_pl.push_front(*other_p_l_it);
      ++other_p_l_it;
    }
    nb_pl.push_front(*p_l_it);
    nb_pll.push_back(nb_pl);
    ++p_l_it;
  }
  return nb_pll;
}

void write_neighbor_list(const MDParameter parm, const ParticlePtrLL nb_pll,
                         const string& path) {
  int counter_a{0};
  Vec data{Vec::Zero(5)};
  for (auto nb_pl : nb_pll) {
    data(0) = counter_a;
    int counter_b{0};
    for (auto p : nb_pl) {
      data(1) = counter_b;
      Vec x{periodic_coordinate(parm, (*p).x)};
      data(2) = x(0);
      data(3) = x(1);
      data(4) = x(2);
      write_data(data, path);
      ++counter_b;
    }
    ++counter_a;
  }
}