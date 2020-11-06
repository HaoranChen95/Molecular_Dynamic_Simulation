#ifndef MDPARAMETER_HPP_
#define MDPARAMETER_HPP_

#include <fstream> 
#include <string> 

#include "additional.hpp"
#include "str_split.hpp"


class MDParameter {

	public:
		MDParameter();
		void read_input(const std::string& path="input", const std::string& suffix=".txt");


		void N(const unsigned long input);
		void epsilon(const double input);
		void sigma(const double input);
		void m(const double input);
		void boundary_width(const double input);
		void time_step(const double input);

		unsigned long N() const;
		double epsilon() const;
		double sigma() const;
		double m() const;
		double boundary_width() const;
		double time_step() const;

	private:

		unsigned long N_;  ///< number of particles in the system
		double epsilon_;  ///< constant in Lenard-Jones potential
		double sigma_;  ///<
		double m_;  ///< single particle mass
		double boundary_width_;  ///< boundary of periodic boundary potential
		double time_step_;  ///< time step

};

#endif
