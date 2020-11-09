#include "write_data.hpp"
using namespace Eigen;
using namespace std;
/** @brief Writes real matrix to name.txt file 
 *
 * Writes eigen matrix with full precison of double. 
 *
 * @param[in] M Matrix of double elements
 * @param[in] path Path including filename, default value data  
 * @param[in] suffix Default value .txt  
 * @param[in] mode Default value ios::out */ 

void write_data(const Mat& M, const string& path, const string& suffix, const ios::openmode mode){
	
	const string n = path + suffix; 
	IOFormat pre(FullPrecision, 0, ",",","); // double precision, alignment of columns, separator "\t"
	ofstream f_out(n, mode);
	if (f_out.is_open()){
		f_out << M.format(pre) << endl;
		f_out.close();
	}
	else{cout << "write_data: File could not be opened, path " << n << endl;}
}
