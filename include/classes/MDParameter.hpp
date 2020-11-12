#ifndef MDPARAMETER_HPP_
#define MDPARAMETER_HPP_

#include <fstream> 
#include <string> 
#include <cmath>

#include "additional.hpp"
#include "str_split.hpp"


class MDParameter{

	public:
		MDParameter();
		void read_input(const std::string& path="input", const std::string& suffix=".txt");


		void N(const unsigned long input);
		void lattice_edge_particles(const unsigned long input);
		void epsilon(const double input);
		void sigma(const double input);
		void m(const double input);
		void boundary_width(const double input);
		void time_step(const double input);
		void time_length(const double input);
		void kT(const double input);
		void neighbor(const double input);

		unsigned long N() const;
		unsigned long lattice_edge_particles() const;
		double epsilon() const;
		double sigma() const;
		double m() const;
		double boundary_width() const;
		double time_step() const;
		double time_length() const;
		double kT() const;
		double neighbor() const;

	private:
		unsigned long lattice_edge_particles_; //the particles number at the edge lattice 
		unsigned long N_;  ///< number of particles in the system
		double epsilon_;  ///< constant in Lenard-Jones potential
		double sigma_;  ///< constant in Lenard-Jones Potential
		double m_;  ///< single particle mass
		double density_;
		double boundary_width_;  ///< boundary of periodic boundary potential
		double time_step_;  ///< time step
		double time_length_; ///< simulation time length
		double kT_; ///< initial system temperature
		double neighbor_; ///< scan radius of neighbor particules

};

#endif
