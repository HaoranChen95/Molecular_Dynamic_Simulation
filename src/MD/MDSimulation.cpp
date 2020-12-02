#include "MDSimulation.hpp"
using namespace std;

void MD_Simulation(const MDParameter parm, ParticlePtrList p_l){
	/**
	 * @brief initialize the neighbor list and initialize f0
	 */

	// ParticlePtrLL nb_ll{neighbors_list_forward(parm, p_l)};
	ParticlePtrLL nb_ll{all_particle_PtrLL(parm, p_l)};
	cout << "neighbor list is built " << parm.neighbor() << endl;
	
	// write_neighbor_list(nb_ll);
	
	ParticlePtrList::iterator p_l_it{p_l.begin()};
	ParticlePtrLL::const_iterator nb_ll_it{nb_ll.begin()};

	// while(p_l_it != p_l.end()){
	// 	(*p_l_it) -> f0 = sum_force(parm, **p_l_it, *nb_ll_it);
		
	// 	++p_l_it;
	// 	++nb_ll_it;
	// }

	init_force_forward(parm, nb_ll);

	// int counter {0};
	// for (ParticleCPtr p: p_l){
	// 	cout << counter << ": " << (*p).f0.norm() << endl;
	// 	++counter;
	// }

	/**
	 * @brief the main part of MD Simulation
	 * 
	 */

	unsigned long steps {static_cast<unsigned long>(parm.time_length()/parm.time_step())};
	for(unsigned long i{0}; i < 100; ++i){
		for(ParticlePtr p : p_l){
			p -> x = velocity_verlet_x(parm, *p);
		}

		p_l_it = p_l.begin();
		nb_ll_it = nb_ll.begin();
		while(p_l_it != p_l.end()){
			(*p_l_it) -> f1 = sum_force(parm, **p_l_it, *nb_ll_it);
			(*p_l_it) -> v = velocity_verlet_v(parm, **p_l_it);
			(*p_l_it) -> f0 = (**p_l_it).f1;
			
			++p_l_it;
			++nb_ll_it;
		}
		
		unsigned equ_time{static_cast<unsigned> (5.0/parm.time_step())};
		if (i < 0){
			double alpha{pow(1.0/2.0*parm.m()*3*parm.N()/kin_energy(parm, p_l),1.0/2.0)};
			for(ParticlePtr p : p_l){
				p -> v = alpha*(*p).v;
			}
		}

		unsigned check_point {static_cast<unsigned> (0.01/parm.time_step())};
		if(i%check_point == 0){
			// nb_ll = neighbors_list_forward(parm, p_l); /** @brief refresh the neighbor list */

			Mat result {Mat::Zero(1,5)};
			result(0,0) = i*parm.time_step();
			double kin_e{kin_energy(parm, p_l)};
			double pot_e{pot_energy_all(parm, p_l)};
			result(0,1) = kin_e;
			result(0,2) = pot_e;
			result(0,3) = kin_e + pot_e;  
			Vec sum_v{Vec::Zero(3)};
			for(ParticlePtr p : p_l){
				sum_v += (*p).v;
			}
			result(0,4) = sum_v.norm();

			write_data(result);
		}
	}

	// for (const Particle p : p_l){cout << p_l.front().f1 <<endl;} //Print f0


	// int counter = 0;
	// for(std::forward_list<ParticlePtrList::const_iterator> p_l_il : p_neighbor){
	
	// cout << counter <<endl;


	// for(ParticlePtrList::iterator p{p_l.begin()}; p != p_l.end(); ++p){
	// 	for(std::forward_list<ParticlePtrList::const_iterator> p_l_il : p_neighbor){
	// 		cout << (*p_l_il.front()).x << endl;
	// 	}
	// }
	cout << "finished MD_Simulation" << endl;
}

double kin_energy(const MDParameter parm, const ParticlePtrList p_l){
	double E{0};
	for(ParticleCPtr p : p_l){
		E += (*p).v.squaredNorm();
	}
	return 0.5*parm.m()*E;
}

double pot_energy(const MDParameter parm, const ParticlePtrLL p_neighbor_ll){
	double E{0};
	for(ParticlePtrList nb_l : p_neighbor_ll){
		for(ParticleCPtr p : nb_l){
			E += Cut_LJ_Potential(parm, (*nb_l.front()).x, (*p).x);
		}
	}
	return 0.5*E;
}

double pot_energy_all(const MDParameter parm, const ParticlePtrList p_l){
	double E{0};
	ParticlePtrList::const_iterator p_l_it {p_l.cbegin()};
	ParticlePtrList::const_iterator other_p_l_it {};
	while (p_l_it != p_l.cend()){
		other_p_l_it = p_l_it;
		++other_p_l_it;
		while (other_p_l_it != p_l.cend()){
			E += Cut_LJ_Potential(parm, (**p_l_it).x, (**other_p_l_it).x);
			++other_p_l_it;
		}
		++p_l_it;
	}
	return E;
}

double pot_energy_forward(const MDParameter parm, const ParticlePtrLL p_neighbor_ll){
	double E{0.0};
	for(ParticlePtrList nb_l : p_neighbor_ll){
		ParticlePtrList::const_iterator nb_l_it {nb_l.cbegin()};
		++nb_l_it;
		while (nb_l_it != nb_l.cend()){
			E += Cut_LJ_Potential(parm, (*nb_l.front()).x, (**nb_l_it).x);
			++nb_l_it;
		}
	}
	return E;
}

void init_force_forward(const MDParameter parm, const ParticlePtrLL nb_ll){ //TODO add the f1 term
	for (ParticlePtrList nb_l : nb_ll){
		
		nb_l.front() -> f0 = Vec::Zero(3);
	}
	for (ParticlePtrList nb_l : nb_ll){
		ParticlePtrList::const_iterator nb_l_it{nb_l.begin()};
		++nb_l_it;
		while(nb_l_it != nb_l.end()){
			Vec force {Cut_LJ_Force(parm, (**nb_l.cbegin()).x, (**nb_l_it).x)};
			nb_l.front() -> f0 += force;
			(**nb_l_it).f0 += force;
			++nb_l_it;
		}
	}
}