#include "main.hpp"
using namespace std;
/** @brief Main executable
 *
 * @param[in] argc Number of input arguments
 * @param[in] argv Input arguments **/
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
	cout << LJ_Potential(g_para, 2.0) << " " << LJ_Force(g_para, 2.0)<< endl;

	Mat i_data{read_data()};

	cout << i_data.row(0) << endl;

	//TODO add partial class and test

	ParticleList particle_list;
	particle_list.AddPartical();
	particle_list.x(i_data.row(0));
	cout << particle_list.x() << endl;
	particle_list.AddPartical();
	particle_list.x(i_data.row(1));
	//particle.head();
	cout << particle_list.x() << endl;

	cout << "leaving main" << endl;
	return 0;
}
