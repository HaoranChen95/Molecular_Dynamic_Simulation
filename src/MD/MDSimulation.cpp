#include "MDSimulation.hpp"
using namespace std;

void MD_Simulation(const MDParameter parm, ParticleList p_l){

	cout << "entering MD_Simulation" << endl;
	static std::forward_list<std::forward_list<const Particle *>> p_neighbor {neighbor(parm, p_l)};//TODO there is a big problem with neighbor function

	cout << "!!!! final position\n" << (*p_neighbor.front().front()).x << endl;
	cout << "!!!! original position\n" << (*neighbor(parm, p_l).front().front()).x << endl;
	/**
	 * @brief calculate the f0 
	 */


	// int i_test = 0;
	// forward_list<Particle*> p_pl; //TODO there is the problem!!!!
	// cout << "the Particle list (positions):" << endl;
	// for (Particle p : p_l){
	// 	cout << "a" << p.x << endl;
	// 	p_pl.push_front(&p);
	// 	cout << "b " << (*p_pl.front()).x << endl;
	// 	cout << "i_test " << i_test <<endl;
	// 	++i_test;
	// 	}

	// i_test = 0;
	// cout << "the Particle pointer list (positions):" << endl;
	// for (auto i : p_pl){cout << "c " << (*i).x << endl;
	// cout << "i_test " << i_test <<endl;
	// ++i_test;
	// }


	// for(ParticleList::iterator p_l_i{p_l.begin()}; p_l_i != p_l.end(); ++p_l_i){
	// 	p_l_i -> f0 = sum_force(parm, *p_l_i, p_l);
	// }

	// unsigned long steps {static_cast<unsigned long>(parm.time_length()/parm.time_step())};
	// for(unsigned long i{0}; i < steps; ++i){

	// 	for(ParticleList::iterator p_l_i{p_l.begin()}; p_l_i != p_l.end(); ++p_l_i){
	// 		p_l_i -> x = velocity_verlet_x(parm, *p_l_i);
	// 	}
	// 	for(ParticleList::iterator p_l_i{p_l.begin()}; p_l_i != p_l.end(); ++p_l_i){
	// 		p_l_i -> f1 = sum_force(parm, *p_l_i, p_l);
	// 		p_l_i -> v = velocity_verlet_v(parm, *p_l_i);
	// 		p_l_i -> f0 = (*p_l_i).f1;
	// 	}
		
	// 	if (i < 1000){
	// 		double alpha{pow(1.0/2.0*parm.m()*3*parm.N()/kin_energy(parm, p_l),1.0/2.0)};
	// 		for(ParticleList::iterator p_l_i{p_l.begin()}; p_l_i != p_l.end(); ++p_l_i){
	// 			p_l_i -> v = alpha*(*p_l_i).v;
	// 		}
	// 	}

	// 	unsigned check_point {static_cast<unsigned> (0.01/parm.time_step())};
	// 	if(i%check_point == 0){
	// 		Mat result {Mat::Zero(1,5)};
	// 		result(0,0) = i*parm.time_step();
	// 		double kin_e{kin_energy(parm, p_l)};
	// 		double pot_e{pot_energy(parm, p_l)};
	// 		result(0,1) = kin_e;
	// 		result(0,2) = pot_e;
	// 		result(0,3) = kin_e + pot_e;
	// 		Vec sum_v{Vec::Zero(3)};
	// 		for(ParticleList::iterator p_l_i{p_l.begin()}; p_l_i != p_l.end(); ++p_l_i){
	// 			sum_v += (*p_l_i).v;
	// 		}
	// 		result(0,4) = sum_v.norm();

	// 		write_data(result);
	// 		}
	// }

	// for (const Particle p : p_l){cout << p_l.front().f1 <<endl;} //Print f0


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

double pot_energy(const MDParameter parm, const ParticleList p_l){ // TODO need to add neighbor function
	double E{0};
	for(Particle p : p_l){
		for(Particle other_p : p_l){
			E += Cut_LJ_Potential(parm, p.x, other_p.x);
		}
	}
	return E;
}