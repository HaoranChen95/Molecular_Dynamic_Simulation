#include "velocity_verlet.hpp"
using namespace std;


Vec velocity_verlet_x(const MDParameter parm, const Particle part){
	cout <<"X\n"<< part.x <<endl <<"V\n"<< part.v << endl <<"F\n"<< part.f0 << endl;
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
Vec sum_force(const MDParameter parm, const Particle part, const std::forward_list<ParticleList::const_iterator> p_il){
	Vec f{Vec::Zero(3)};

	for (ParticleList::const_iterator i : p_il){
		f += Cut_LJ_Force(parm, part.x, (*i).x);
	}
	return f;
}
