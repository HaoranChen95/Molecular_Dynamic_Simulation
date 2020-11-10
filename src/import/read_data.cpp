#include "read_data.hpp"
using namespace Eigen;
using namespace std;
/** @brief Helper function determining number of rows and columns of data
 *
 * @param[in] path path to read file
 * @param[in] suffix suffix of file 
 * @version checked */
pair<Unsign, Unsign> get_rows_cols(const string& path, const string& suffix){
	const string& n = path + suffix;
	Unsign cols = 0, rows = 0;
	string line = "";
	
	ifstream f_in_col(n, ios::in);
	if (f_in_col.is_open()){
		getline(f_in_col, line);
		const auto& a = str_split(line, '\t');
		cols = a.size();
		f_in_col.close();	
	}
	else{cout << "read_data get_rows_cols: File could not be opened -> reading columns of path " + n << endl;}

	ifstream f_in_row(n, ios::in);
	if (f_in_row.is_open()){
		while(getline(f_in_row, line)){rows = rows + 1;}
		f_in_row.close();
	}
	else{cout << "read_data get_rows_cols: File could not be opened -> reading rows of path " + n << endl;}

	return {rows, cols};
}

/** @brief Reads a real vector or matrix without optimization and checks for nan/inf
 *
 * @param[in] path path to read file
 * @param[in] suffix suffix of file 
 * @version checked */
Mat read_data(const string& path, const string& suffix){
	
	const auto a = get_rows_cols(path, suffix);
	const Unsign rows = a.first;
	const Unsign cols = a.second;
	Mat M = Mat::Zero(rows, cols);

	const string& n = path + suffix;
	ifstream f_in(n, ios::in);

	if (f_in.is_open()){
		istream_iterator<double> start(f_in);
		istream_iterator<double> end;
		vector<double> v = {start, end};
		for (Unsign i=0; i<rows; i++){
			for (Unsign j=0; j<cols; j++){M(i,j) = v[i*cols + j];}
		}	
		f_in.close();	
	}
	else{cout << "read_data: File could not be opened -> read_data with path " + n << endl;}
	is_reg(M);

	return M;
}

/** @brief Reads a real vector or matrix with optimization by caller function via get_rows_cols and checks for nan
 *
 * @param[in] M matrix of dimension (rows, cols) 
 * @param[in] path path to read file
 * @param[in] rows number of rows of Matrix to be read 
 * @param[in] cols number of cols of Matrix to be read 
 * @param[in] suffix suffix of file 
 * @version checked */
void read_data(Mat& M, const Unsign rows, const Unsign cols, const std::string& path, const std::string suffix){
	
	const string& n = path + suffix;
	ifstream f_in(n, ios::in);
	M = Mat::Zero(rows, cols);

	if (f_in.is_open()){
		istream_iterator<double> start(f_in);
		istream_iterator<double> end;
		vector<double> v = {start, end};
		for (Unsign i=0; i<rows; i++){
			for (Unsign j=0; j<cols; j++){M(i,j) = v[i*cols + j];}
		}	
		f_in.close();	
	}
	else{cout << "read_data: File could not be opened -> read_data with path " + n << endl;}
	
	is_reg(M);
}
