#include "main.hpp"
using namespace std;
/** @brief Main executable
 *
 * @param[in] argc Number of input arguments
 * @param[in] argv Input arguments **/

//Todo change force function
double one_force(const double r){
	return r;
}

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

	Mat i_data;
	read_data(i_data,8);

	//cout << i_data << endl; 

	// ParticleList particle_list;
	// for(long unsigned int i{0} ; i<2 ; ++i){
	// particle_list.AddPartical();
	// particle_list.x(i_data.row(2*i));
	// particle_list.v(i_data.row(2*i+1));
	// }

	ParticleList particle_list; 	//TODO need to intergrat to a function
	particle_list.AddPartical();
	particle_list.x_old(i_data.row(0));
	particle_list.v_old(i_data.row(1));

	particle_list.AddPartical();
	particle_list.x_old(i_data.row(2));
	particle_list.v_old(i_data.row(3));

	particle_list.AddPartical();
	particle_list.x_old(i_data.row(4));
	particle_list.v_old(i_data.row(5));

	particle_list.AddPartical();
	particle_list.x_old(i_data.row(6));
	particle_list.v_old(i_data.row(7));

	//particle_list.PrintList_x();

	particle_list.head();
	cout << particle_list.x() << endl;
	particle_list.next();
	cout << particle_list.x() << endl;

	//cout << periodic_force(particle_list.x(),particle_list.v(), one_force, g_para) << endl;

	//cout << periodic_boundary(particle_list.x(), g_para) << endl;

	cout << "leaving main" << endl;
	return 0;
}
