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

	cout << "leaving main" << endl;
}
