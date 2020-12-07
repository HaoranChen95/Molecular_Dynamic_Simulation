#include "lattice.hpp"
using namespace std;

/**
 * @brief build the initial lattice and calculate the force
 *
 * @param parm
 * @return ParticlePtrList
 */

ParticlePtrList init_lattice(const MDParameter parm) {
  ParticlePtrList p_l;

  std::random_device rd{};
  std::mt19937 generator{rd()};
  std::normal_distribution<double> distribution(0.0, parm.kT());
  Vec temp{Vec::Zero(3)};

  /** @brief first build particles with lattice position and normal distribution
   * velocities*/
  for (unsigned long i{0}; i < parm.lattice_edge_particles(); ++i) {
    for (unsigned long j{0}; j < parm.lattice_edge_particles(); ++j) {
      for (unsigned long k{0}; k < parm.lattice_edge_particles(); ++k) {
        Particle new_particle;

        temp[0] = (i + 0.5) * parm.lattice_constant();
        temp[1] = (j + 0.5) * parm.lattice_constant();
        temp[2] = (k + 0.5) * parm.lattice_constant();
        new_particle.x = temp;

        temp[0] = distribution(generator);
        temp[1] = distribution(generator);
        temp[2] = distribution(generator);
        new_particle.v = temp;

        p_l.push_front(make_shared<Particle>(new_particle));
      }
    }
  }

  /**
   * @brief sum the velocities to shift the system total velocity back to 0
   */
  temp = Vec::Zero(3);
  for (const shared_ptr<Particle> p : p_l) {
    temp += (*p).v;
  }
  temp = temp / (double)parm.N();

  for (shared_ptr<Particle> p : p_l) {
    p->v -= temp;
  }

  return p_l;
}

void write_ParticleList(const ParticlePtrList p_l, const string& path,
                        const string& suffix) {
  Mat data{Mat::Zero(1, 14)};
  for (ParticleCPtr p : p_l) {
    data(0) = (*p).x(0);
    data(1) = (*p).x(1);
    data(2) = (*p).x(2);
    data(3) = (*p).x.norm();

    data(5) = (*p).v(0);
    data(6) = (*p).v(1);
    data(7) = (*p).v(2);
    data(8) = (*p).v.norm();

    data(10) = (*p).f0(0);
    data(11) = (*p).f0(1);
    data(12) = (*p).f0(2);
    data(13) = (*p).f0.norm();

    write_data(data, path, suffix);
  }
}

ParticlePtrList read_ParticleList(const string& path, const string& suffix) {
  Particle new_particle;
  ParticlePtrList p_l;
  const string& n = path + suffix;

  ifstream f(n, ios::in);
  if (f.is_open()) {
    for (string line; getline(f, line);) {
      const auto& a = str_split(line, ',');
      new_particle.x(0) = stod(a[0]);
      new_particle.x(1) = stod(a[1]);
      new_particle.x(2) = stod(a[2]);
      new_particle.v(0) = stod(a[5]);
      new_particle.v(1) = stod(a[6]);
      new_particle.v(2) = stod(a[7]);
      p_l.push_front(make_shared<Particle>(new_particle));
    }
    f.close();
  } else {
    cout << "read_data get_rows_cols: File could not be opened -> reading "
            "columns of path " +
                n
         << endl;
  }

  // for(int i{0}; i < data.rows(); ++i){
  //   new_particle.x(0) = data(i,0);
  //   new_particle.x(1) = data(i,1);
  //   new_particle.x(2) = data(i,2);
  //   new_particle.v(0) = data(i,5);
  //   new_particle.v(1) = data(i,6);
  //   new_particle.v(2) = data(i,7);
  //   p_l.push_front(make_shared<Particle> (new_particle));
  // }
  return p_l;
}