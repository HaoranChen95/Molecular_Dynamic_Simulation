#include "assign.hpp"
using namespace std;
/** @brief Assigning input arguments from shell script start.sh
 *
 * Input arguments are assigned to global MDParamter object.
 * 
 * @param[in] para input MDParameter class to get timestep
 * @param[in] argc Number of input arguments
 * @param[in] argv Input arguments **/
void assign(MDParameter& para, const unsigned argc, const char* argv[]){
	cout << "entering assign" << endl;

	if (3 == argc){
		para.time_length(stod(argv[1]));
		para.time_step(stod(argv[2]));
	}
	else{
		const string s = "Call executable with 2 input arguments";
		throw(runtime_error(s));
	}

	
	cout << "leaving assign" << endl;
}
