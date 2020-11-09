#include "MDSimulation.hpp"
using namespace std;

void MD_Simulation(ParticleList *p_l, MDParameter parm){
	sum_force(p_l[0], LJ_Force, parm);
	for (unsigned long i {static_cast<unsigned long int>(parm.time_length()/parm.time_step())}; i > 0; --i){
		cout << i << endl;
		velocity_verlet_x(p_l, parm);
		cout << "check point 1" << endl;
		sum_force(p_l[1], LJ_Force, parm);
		cout << "check point 2" << endl;
		velocity_verlet_v(p_l, parm);
		cout << "check point 3" << endl;
		p_l[0] = p_l[1];

		p_l[0].head();
		write_data(p_l[0].x());
	}
	cout << "finished MD_Simulation" << endl;
	
}
