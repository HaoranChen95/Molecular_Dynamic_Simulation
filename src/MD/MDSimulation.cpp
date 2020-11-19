#include "MDSimulation.hpp"
using namespace std;

void MD_Simulation(const MDParameter parm, ParticleList p_l){

	cout << "entering MD_Simulation" << endl;
	std::forward_list<std::forward_list<const Particle *>> p_neighbor {neighbor(parm, p_l)};//TODO there is a big problem with neighbor function

	cout << "!!!! final position\n" << (*p_neighbor.front().front()).x << endl;
	cout << "!!!! original position\n" << (*neighbor(parm, p_l).front().front()).x << endl;
	/**
	 * @brief calculate the f0 
	 */

	// for(ParticleList::iterator p_l_i{p_l.begin()}; p_l_i != p_l.end(); ++p_l_i){
	// 	p_l_i -> f0 = sum_force(parm, (*p_l_i), p_l);
	// }
	// int counter = 0;
	// for(std::forward_list<ParticleList::const_iterator> p_l_il : p_neighbor){
	
	// cout << counter <<endl;


	// for(ParticleList::iterator p_l_i{p_l.begin()}; p_l_i != p_l.end(); ++p_l_i){
	// 	for(std::forward_list<ParticleList::const_iterator> p_l_il : p_neighbor){
	// 		cout << (*p_l_il.front()).x << endl;
	// 	}
	// }
	cout << "finished MD_Simulation" << endl;
}

double kin_energy(const MDParameter parm, const ParticleList p_l){
	double E{0};
	for(Particle p : p_l){
		E += p.v.squaredNorm();
	}
	return 1/2.0*parm.m()*E;
}

double pot_energy(std::forward_list<std::forward_list<ParticleList::const_iterator>> p_n){
	double E{0};
	return E;
}