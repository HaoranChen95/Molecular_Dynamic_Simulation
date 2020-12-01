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

Vec sum_force(const MDParameter parm, const Particle part, const ParticleCPtrL p_pl){
	Vec f{Vec::Zero(3)};
	for (ParticleCPtr i : p_pl){
		f += Cut_LJ_Force(parm, part.x, (*i).x);
	}
	return f*48.0*parm.epsilon()*pow(parm.sigma(),-2.0);
}

bool is_neighbor(const MDParameter parm, const Particle p_a, const Particle p_b){
	double r{periodic_vector(parm, p_a.x, p_b.x).norm()};
	return  r < parm.neighbor() && r != 0;
}

ParticleCPtrLL neighbors_list(const MDParameter parm, const ParticlePtrList p_l){
	ParticleCPtrLL nb_pll;
	for (ParticleCPtr p : p_l){
		ParticleCPtrL nb_pl{};
		for (ParticleCPtr other_p : p_l){
			if(is_neighbor(parm, *p, *other_p)){
				nb_pl.push_front(other_p);
			}
		}
		nb_pl.push_front(p);
		nb_pll.push_back(nb_pl);
	}
	return nb_pll;
}

ParticleCPtrLL all_particle_PtrLL(const MDParameter parm, const ParticlePtrList p_l){
	ParticleCPtrLL nb_pll;
	for (ParticleCPtr p : p_l){
		ParticleCPtrL nb_pl{};
		for (ParticleCPtr other_p : p_l){
			if(p != other_p){
				nb_pl.push_front(other_p);
			}
		}
		nb_pl.push_front(p);
		nb_pll.push_back(nb_pl);
	}
	return nb_pll;
}