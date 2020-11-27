#include "main.hpp"

using namespace std;
/** @brief Main executable
 *
 * @param[in] argc Number of input arguments
 * @param[in] argv Input arguments **/

//TODO change the force potential to cut LJ potential and force
//TODO change the in put data class
//TODO add energy calculation function
//TODO add efficient radius

int main(const int argc, const char* argv[]){
	cout << "entering main" << endl;
	
	try{assign(g_para, argc, argv);}
	catch(const runtime_error& err){
		cout << err.what() << endl;
		return 1;	
	}

	cout <<"time step:\t\t" << g_para.time_step() << endl;

	g_para.read_input();


	// MD simulations goes here
	ParticlePtrList p_l{init_lattice(g_para)};
	if (!p_l.empty()){
		cout << "first particle position\n" << (*p_l.front()).x << endl;
		
		/** @brief print the p_l*/
		// int counter{1};
		// for (ParticleCPtr p : p_l){
		// 	cout << counter << ":\n" << (*p).x << endl;
		// 	++counter;
		// }
		
		MD_Simulation(g_para, p_l);

		// int i_test = 0;
		// forward_list<const Particle*> p_pl; //TODO there is the problem!!!!
		// cout << "the Particle list (positions):" << endl;
		// for (forward_list<Particle>::const_iterator p_it{p_l.cbegin()}; p_it != p_l.cend(); ++p_it){
		// 	cout << "a" << (*p_it).x << endl;
		// 	p_pl.push_front(&*p_it);
		// 	cout << "b " << (*p_pl.front()).x << endl;
		// 	cout << "i_test " << i_test <<endl;
		// 	++i_test;
		// }

		// i_test = 0;
		// cout << "the Particle pointer list (positions):" << endl;
		// for (auto i : p_pl){
		// 	cout << "c " << (*i).x << endl;
		// 	cout << "i_test " << i_test <<endl;
		// 	++i_test;
		// }

	}

	cout << "leaving main" << endl;
	return 0;
}
