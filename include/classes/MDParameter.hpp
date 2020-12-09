#ifndef MDPARAMETER_HPP_
#define MDPARAMETER_HPP_

#include <cmath>
#include <fstream>
#include <string>

#include "additional.hpp"
#include "read_data.hpp"
#include "str_split.hpp"
#include "write_data.hpp"

class MDParameter {
 public:
  MDParameter();
  void read_input(const std::string& path = "input",
                  const std::string& suffix = ".txt");

  void N(const unsigned long input);
  void lattice_edge_particles(const unsigned long input);
  void epsilon(const double input);
  void sigma(const double input);
  void m(const double input);
  void boundary_width(const double input);
  void lattice_constant(const double input);
  void time_step(const double input);
  void time_length(const double input);
  void kT(const double input);
  void neighbor(const double input);
  void scattering_time(const double input);
  void open_nnl(const int input);
  void simple_alpha(const bool input);

  void print();

  unsigned long N() const;
  unsigned long lattice_edge_particles() const;
  double epsilon() const;
  double sigma() const;
  double m() const;
  double boundary_width() const;
  double lattice_constant() const;
  double time_step() const;
  double time_length() const;
  double kT() const;
  double neighbor() const;
  double scattering_time() const;
  int open_nnl() const;
  bool simple_alpha() const;

 private:
  unsigned long
      lattice_edge_particles_;  // the particles number at the edge lattice
  unsigned long N_;             ///< number of particles in the system
  double epsilon_;              ///< constant in Lenard-Jones potential
  double sigma_;                ///< constant in Lenard-Jones Potential
  double m_;                    ///< single particle mass
  double density_;              ///< density of system N/V
  double boundary_width_;       ///< boundary of periodic boundary potential
  double lattice_constant_;
  double kT_;  ///< initial system temperature

  double time_step_;    ///< time step
  double time_length_;  ///< simulation time length
  double neighbor_;     ///< scan radius of neighbor particules
  double scattering_time_;
  int open_nnl_;
  bool simple_alpha_;
};

#endif
