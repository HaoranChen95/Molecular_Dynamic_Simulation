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
	try{assign(parm, argc, argv);}
	catch(const runtime_error& err){
		cout << err.what() << endl;
		return 1;	
	}

	cout <<"time step:\t\t" << parm.time_step() << endl;

	parm.read_input();

	test_Cut_LJ_Potential(parm);

	// MD simulations goes here
	ParticlePtrList p_l{init_lattice(parm)};
	if (!p_l.empty()){
		/** @brief print the p_l*/
		// int counter{1};

		// for (ParticleCPtr p : p_l){
		// 	cout << counter << ":\n" << (*p).x << endl;
		// 	++counter;
		// }
		
		
		MD_Simulation(parm, p_l);
	}

	/** @brief out put program runing time */
	long int difftime {1000*(clock() - begin_time)/CLOCKS_PER_SEC};
	long int diffmin {difftime/60000};
	long int diffsec {(difftime%60000)/1000};
	long int diffmsec {difftime%1000};
	cout << "leaving main, and used time: " << diffmin << " m " << diffsec << " s " << diffmsec << endl;
	return 0;
}
