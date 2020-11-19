#include "MDSimulation.hpp"
using namespace std;

void MD_Simulation(const MDParameter parm, ParticleList p_l){

	std::forward_list<std::forward_list<ParticleList::const_iterator>> p_neighbor{neighbor(parm, p_l)};

	for(ParticleList::iterator p_l_i{p_l.begin()}; p_l_i != p_l.end(); ++p_l_i){
		
	}
	cout << "finished MD_Simulation" << endl;
	
}

// void MD_Simulation_Plus(list<Particle>& p_l, const MDParameter parm);