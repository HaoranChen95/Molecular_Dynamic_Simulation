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
	
	clock_t begin_time{clock()};
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
	}

	long int difftime {1000*(clock() - begin_time)/CLOCKS_PER_SEC};
	long int diffmin {difftime/60000};
	long int diffsec {(difftime%60000)/1000};
	long int diffmsec {difftime%1000};
	cout << "leaving main, and used time: " << diffmin << " m " << diffsec << " s " << diffmsec << endl;
	return 0;
}
