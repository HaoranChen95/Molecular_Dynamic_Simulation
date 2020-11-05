#include "main.hpp"
using namespace std;
/** @brief Main executable
 *
 * @param[in] argc Number of input arguments
 * @param[in] argv Input arguments **/
int main(const int argc, const char* argv[]){
	cout << "entering main" << endl;

	try{assign(argc, argv);}
	catch(const runtime_error& err){
		cout << err.what() << endl;
		return 1;	
	}


	// MD simulations goes here
		

	cout << "leaving main" << endl;
}
