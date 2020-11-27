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

Vec sum_force(const MDParameter parm, const Particle part, const ParticleCPL p_pl){
	Vec f{Vec::Zero(3)};
	for (const Particle *i : p_pl){
		f += Cut_LJ_Force(parm, part.x, (*i).x);
	}
	return f*48.0*parm.epsilon()*pow(parm.sigma(),-2.0);
}

bool is_neighbor(const MDParameter parm, const Particle p_a, const Particle p_b){
	return periodic_vector(parm, p_a.x, p_b.x).norm() < parm.neighbor();
}

ParticleCPLL neighbors_list(const MDParameter parm, const ParticleList p_l){
	ParticleCPLL nb_pll;
	for (ParticleList::const_iterator p_l_it{p_l.cbegin()}; p_l_it != p_l.cend(); ++p_l_it){
		ParticleCPL nb_pl{};
		for (ParticleList::const_iterator other_p_l_it{p_l.cbegin()}; other_p_l_it != p_l.cend(); ++other_p_l_it){
			if(is_neighbor(parm, *p_l_it, *other_p_l_it)){
				nb_pl.push_front(&*other_p_l_it);
			}
		}
		nb_pl.push_front(&*p_l_it);
		nb_pll.push_back(nb_pl);//TODO new problem race at there
	}

	cout << "in the neighbors_list" <<endl;

	for (ParticleCPL::const_iterator nb_pl_it{nb_pll.front().cbegin()}; nb_pl_it != nb_pll.front().cend(); ++nb_pl_it){
		cout << "first neighbor_x \n" << (*(*nb_pl_it)).x <<endl;
	}
	
	cout << "out of neighbors_list" <<endl;
	return nb_pll;
}