#include "lattice.hpp"
using namespace std;

/**
 * @brief build the initial lattice and calculate the force
 * 
 * @param parm 
 * @return ParticleList 
 */

ParticleList init_lattice(const MDParameter parm){
	ParticleList p_l;
	
	std::random_device rd{};
	std::mt19937 generator{rd()};
	std::normal_distribution<double> distribution(0.0,parm.kT());
	Vec temp{Vec::Zero(3)};
	
	/** @brief first build particles with lattice position and normal distribution velocities*/ 
	for (unsigned long i{0}; i < parm.lattice_edge_particles(); ++i){ 
		for (unsigned long j{0}; j < parm.lattice_edge_particles(); ++j){
			for (unsigned long k{0}; k < parm.lattice_edge_particles(); ++k){
				Particle new_particle;

				temp[0]	= (i+0.5)*parm.lattice_constant();
				temp[1] = (j+0.5)*parm.lattice_constant();
				temp[2] = (k+0.5)*parm.lattice_constant();
				new_particle.x = temp;

				temp[0]	= distribution(generator);
				temp[1] = distribution(generator);
				temp[2] = distribution(generator); 
				new_particle.v = temp;

				p_l.push_front(new_particle);
			}
		}
	}

	/**
	 * @brief sum the velocities to shift the system total velocity back to 0
	 */
	temp = Vec::Zero(3);
	for (Particle p : p_l){
		temp += p.v; 
	}
	temp = temp/(double)parm.N();

	ParticleList::iterator p_l_iter;
	for (p_l_iter = p_l.begin(); p_l_iter != p_l.end(); p_l_iter++){
		p_l_iter->v -= temp; 

		// std::forward_list<ParticleList::const_iterator> p_il;
		// for (ParticleList::iterator p_i{p_l.begin()};p_i != p_l.end(); ++p_i){
		// 	p_il.push_front(p_i);
		// }
		// p_l_iter->f0 = sum_force(parm, *p_l_iter, p_il);
	}

	p_l.reverse();
	cout << "initial latice with position and velocities is built." << endl;
	return p_l;
}