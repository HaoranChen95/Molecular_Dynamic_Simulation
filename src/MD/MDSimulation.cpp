#include "MDSimulation.hpp"
using namespace std;

void MD_Simulation(ParticleList *p_l, MDParameter parm){
	sum_force(p_l[0], LJ_Force, parm);
	for (unsigned long i {static_cast<unsigned long int>(parm.time_length()/parm.time_step())}; i > 0; --i){
		cout << i << endl;
		velocity_verlet_x(p_l, parm);
		sum_force(p_l[1], LJ_Force, parm);
		velocity_verlet_v(p_l, parm);
		p_l[0] = p_l[1];

		p_l[0].head();
		write_data(p_l[0].x(), "x1");
		p_l[0].next();
		write_data(p_l[0].x(), "x2");
		p_l[0].next();
		write_data(p_l[0].x(), "x3");
		p_l[0].next();
		write_data(p_l[0].x(), "x4");
	}
	cout << "finished MD_Simulation" << endl;
	
}

// void MD_Simulation_Plus(list<Particle>& p_l, const MDParameter parm);