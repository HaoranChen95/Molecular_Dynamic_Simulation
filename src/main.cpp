#include "main.hpp"

using namespace std;
/** @brief Main executable
 *
 * @param[in] argc Number of input arguments
 * @param[in] argv Input arguments **/

//TODO intergrat the initial value setteling function
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

	//cout << i_data << endl; 

	// ParticleList particle_list;
	// for(long unsigned int i{0} ; i<2 ; ++i){
	// particle_list.AddPartical();
	// particle_list.x(i_data.row(2*i));
	// particle_list.v(i_data.row(2*i+1));
	// }

	// ParticleList particle_list[2]; 	//TODO need to intergrat to a function
	// initial_lattice(particle_list, g_para);
	// particle_list[0].AddPartical();
	// particle_list[1].AddPartical();
	// particle_list[0].x(i_data.row(0));
	// particle_list[0].v(i_data.row(1));

	// particle_list[0].AddPartical();
	// particle_list[1].AddPartical();
	// particle_list[0].x(i_data.row(2));
	// particle_list[0].v(i_data.row(3));

	// particle_list[0].AddPartical();
	// particle_list[1].AddPartical();
	// particle_list[0].x(i_data.row(4));
	// particle_list[0].v(i_data.row(5));

	// particle_list[0].AddPartical();
	// particle_list[1].AddPartical();
	// particle_list[0].x(i_data.row(6));
	// particle_list[0].v(i_data.row(7));

	//write_data(i_data);

	//particle_list[0].PrintList_x();

	// MD_Simulation(particle_list, g_para);

	// cout << "positions: \n";
	// particle_list[0].head();
	// cout << "x 1\n" << particle_list[0].x() << endl;
	// particle_list[0].next();
	// cout << "x 2\n" << particle_list[0].x() << endl;
	// particle_list[0].next();
	// cout << "x 3\n" << particle_list[0].x() << endl;
	// particle_list[0].next();
	// cout << "x 4\n" << particle_list[0].x() << endl;

	// sum_force(particle_list[0], one_force, g_para);
	// particle_list[0].head();
	// write_data(particle_list[0].f());
	// cout << "Force 1\n" << particle_list[0].f() << endl;
	// particle_list[0].next();
	// write_data(particle_list[0].f());
	// cout << "Force 2\n" << particle_list[0].f() << endl;
	// particle_list[0].next();
	// write_data(particle_list[0].f());
	// cout << "Force 3\n" << particle_list[0].f() << endl;
	// particle_list[0].next();
	// write_data(particle_list[0].f());
	// cout << "Force 4\n" << particle_list[0].f() << endl;

	cout << "leaving main" << endl;
	return 0;
}
