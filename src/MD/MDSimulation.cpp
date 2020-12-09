#include "MDSimulation.hpp"
using namespace std;

void MD_Simulation(const MDParameter parm, ParticlePtrList p_l) {
  /**
   * @brief initialize the neighbor list and initialize f0
   */

  ParticlePtrLL nb_ll;

  if (parm.open_nnl() == 0) {
    cout << "neighbors list is closed" << endl;
    nb_ll = all_particle_PtrLL(p_l);
  } else {
    cout << "neighbors list is opened" << endl;
    nb_ll = neighbors_list_forward(parm, p_l);
  }

  write_neighbor_list(parm, nb_ll);

  force_forward(parm, nb_ll);

  /**
   * @brief the main part of MD Simulation
   *
   */

  unsigned long steps{
      static_cast<unsigned long>(parm.time_length() / parm.time_step())};
  for (unsigned long i{0}; i < steps; ++i) {

    /**
     * @brief each check point refresh the neighbor list and out put the energy
     *
     */
    unsigned check_point{static_cast<unsigned>(0.01 / parm.time_step())};
    if (i % check_point == 0) {
      double pot_e{0};

      switch (parm.open_nnl()) {
        case 0:
          pot_e = pot_energy_all(parm, p_l);
          break;

        case 1:
          nb_ll = neighbors_list_forward(
              parm, p_l); /** @brief refresh the neighbor list */
          pot_e = pot_energy_forward(parm, nb_ll);
          break;

        case 2:
          if (nnl_refresh(parm, nb_ll)) {
            nb_ll = neighbors_list_forward(parm, p_l);
          }
          pot_e = pot_energy_forward(parm, nb_ll);
          break;
      }
      // if (parm.open_nnl()) {
      //   nb_ll = neighbors_list_forward(
      //       parm, p_l); /** @brief refresh the neighbor list */
      //   pot_e = pot_energy_forward(parm, nb_ll);
      // } else {
      //   pot_e = pot_energy_all(parm, p_l);
      // }
      double kin_e{kin_energy(parm, p_l)};

      Vec result{Vec::Zero(6)};
      result(0) = i * parm.time_step();
      result(1) = kin_e;
      result(2) = pot_e;
      result(3) = kin_e + pot_e;
      result(4) = mean_sqrt_trajectory(parm, p_l);
      Vec sum_v{Vec::Zero(3)};
      for (ParticlePtr p : p_l) {
        sum_v += (*p).v;
      }
      result(5) = sum_v.norm();
      write_ParticleList(parm, p_l, "p_l_all_time");
      write_data(result);
    }


    for (ParticlePtr p : p_l) {
      p->x = velocity_verlet_x(parm, *p);
    }

    force_forward(parm, nb_ll);

    for (ParticlePtr p : p_l) {
      p->v = velocity_verlet_v(parm, *p);
    }

    double alpha{1};
    unsigned equ_time{
        static_cast<unsigned>(parm.scattering_time() / parm.time_step())};
    if (i < equ_time) {
      double new_alpha{
          pow(1.0 / 2.0 * parm.m() * 3 * parm.N() / kin_energy(parm, p_l),
              1.0 / 2.0)};

      if (parm.simple_alpha()) {
        alpha = new_alpha;
      } else {
        double frac{static_cast<double>(i)};
        alpha = (alpha * frac + new_alpha) / (frac + 1.0);
      }

      for (ParticlePtr p : p_l) {
        p->v = alpha * (*p).v;
      }
    }
  }

  cout << "finished MD_Simulation" << endl;
}

double kin_energy(const MDParameter parm, const ParticlePtrList p_l) {
  double E{0};
  for (ParticleCPtr p : p_l) {
    E += (*p).v.squaredNorm();
  }
  return 0.5 * parm.m() * E;
}

double pot_energy(const MDParameter parm, const ParticlePtrLL p_neighbor_ll) {
  double E{0};
  for (ParticlePtrList nb_l : p_neighbor_ll) {
    for (ParticleCPtr p : nb_l) {
      E += Cut_LJ_Potential(parm, (*nb_l.front()).x, (*p).x);
    }
  }
  return 0.5 * E;
}

double pot_energy_all(const MDParameter parm, const ParticlePtrList p_l) {
  double E{0};
  ParticlePtrList::const_iterator p_l_it{p_l.cbegin()};
  ParticlePtrList::const_iterator other_p_l_it{};
  while (p_l_it != p_l.cend()) {
    other_p_l_it = p_l_it;
    ++other_p_l_it;
    while (other_p_l_it != p_l.cend()) {
      E += Cut_LJ_Potential(parm, (**p_l_it).x, (**other_p_l_it).x);
      ++other_p_l_it;
    }
    ++p_l_it;
  }
  return E;
}

double pot_energy_forward(const MDParameter parm,
                          const ParticlePtrLL p_neighbor_ll) {
  double E{0.0};
  for (ParticlePtrList nb_l : p_neighbor_ll) {
    ParticlePtrList::const_iterator nb_l_it{nb_l.cbegin()};
    ++nb_l_it;
    while (nb_l_it != nb_l.cend()) {
      E += Cut_LJ_Potential(parm, (*nb_l.front()).x, (**nb_l_it).x);
      ++nb_l_it;
    }
  }
  return E;
}

void force_forward(const MDParameter parm, const ParticlePtrLL nb_ll) {
  for (ParticlePtrList nb_l : nb_ll) {
    nb_l.front()->f1 = (*nb_l.front()).f0;
    nb_l.front()->f0 = Vec::Zero(3);
  }
  for (ParticlePtrList nb_l : nb_ll) {
    ParticlePtrList::const_iterator nb_l_it{nb_l.begin()};
    ++nb_l_it;
    while (nb_l_it != nb_l.end()) {
      Vec force{Cut_LJ_Force(parm, (**nb_l.cbegin()).x, (**nb_l_it).x)};
      nb_l.front()->f0 += force;
      (**nb_l_it).f0 -= force;
      ++nb_l_it;
    }
  }
}

double mean_sqrt_trajectory(const MDParameter parm, const ParticlePtrList p_l) {
  double result{0.0};

  vector<Vec> init_x;
  Vec temp{Vec::Zero(3)};
  for (unsigned long i{0}; i < parm.lattice_edge_particles(); ++i) {
    for (unsigned long j{0}; j < parm.lattice_edge_particles(); ++j) {
      for (unsigned long k{0}; k < parm.lattice_edge_particles(); ++k) {
        temp[0] = (i + 0.5) * parm.lattice_constant();
        temp[1] = (j + 0.5) * parm.lattice_constant();
        temp[2] = (k + 0.5) * parm.lattice_constant();

        init_x.push_back(temp);
      }
    }
  }

  vector<Vec>::const_iterator init_x_it{init_x.cbegin()};

  for (ParticleCPtr p : p_l) {
    result += ((*p).x - (*init_x_it)).squaredNorm();
    ++init_x_it;
  }
  return result / parm.N();
}