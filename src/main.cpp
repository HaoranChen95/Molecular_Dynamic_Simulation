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
	ParticleList p_l{init_lattice(g_para)};
	if (!p_l.empty()){
		cout << "first particle position\n" << p_l.front().x << endl;
		cout << &(*p_l.cbegin()) << endl;
		MD_Simulation(g_para, p_l);
	}

	cout << "leaving main" << endl;
	return 0;
}
