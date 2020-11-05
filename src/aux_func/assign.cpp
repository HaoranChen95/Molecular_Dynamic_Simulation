#include "assign.hpp"
using namespace std;
/** @brief Assigning input arguments from shell script start.ssh
 *
 * Input arguments are assigned to global MDParamter object.
 *
 * @param[in] argc Number of input arguments
 * @param[in] argv Input arguments **/
void assign(const unsigned argc, const char* argv[]){
	cout << "entering assign" << endl;

	// TODO replace 2 by number of input arguments you would like to have for a regular run
	if (2 == argc){
	
		// TODO convert argv here and assign to global MDParameter object

	
	}
	else{
		const string s = "Call executable with 2 input arguments";
		throw(runtime_error(s));
	}

	
	cout << "leaving assign" << endl;
}
