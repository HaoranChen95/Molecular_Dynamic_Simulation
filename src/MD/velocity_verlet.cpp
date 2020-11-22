#include "velocity_verlet.hpp"
using namespace std;


Vec velocity_verlet_x(const MDParameter parm, const Particle part){
	return periodic_coordinate(parm, part.x + part.v*parm.time_step() + part.f0/2.0/parm.m()*pow(parm.time_step(),2));
}

Vec velocity_verlet_v(const MDParameter parm, const Particle part){
	return part.v+(part.f0+part.f1)/2.0/parm.m()*parm.time_step();
}

/**
 * @brief calculate the force at particle from the other particle const_iterator list
 * 
 * @param[in] parm 
 * @param[in] part 
 * @param[in] p_il 
 * @return Vec 
 */
//TODO change the in put particle list to pointer list
Vec sum_force(const MDParameter parm, const Particle part, const std::forward_list<Particle> p_l){
	Vec f{Vec::Zero(3)};
	for (const Particle i : p_l){
		f += Cut_LJ_Force(parm, part.x, i.x);
	}
	return f;
}
