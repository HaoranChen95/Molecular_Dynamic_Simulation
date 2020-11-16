#include "main.hpp"

using namespace std;
/** @brief Main executable
 *
 * @param[in] argc Number of input arguments
 * @param[in] argv Input arguments **/

//TODO change the force potential to cut LJ potential and force
//TODO change the in put data class
//TODO add energy calculation function

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
	std::list<Particle> p_l{init_lattice(g_para)};
	if (!p_l.empty()){
		cout << "first particle position" << p_l.front().x << endl;
	}
	

	// Mat i_data; //TODO change the read_data return data type
	// read_data(i_data,8);

	cout << "leaving main" << endl;
	return 0;
}
