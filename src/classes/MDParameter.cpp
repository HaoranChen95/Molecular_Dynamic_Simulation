/** @class
 *
 *
 */
#include "MDParameter.hpp"
using namespace std;

MDParameter::MDParameter() = default;

void MDParameter::N(const unsigned long input)			{N_ = input;};
void MDParameter::epsilon(const double input)			{epsilon_ = input;};
void MDParameter::sigma(const double input)				{sigma_ = input;};
void MDParameter::m(const double input)					{m_ = input;};
void MDParameter::boundary_width(const double input)	{boundary_width_ = input;};
void MDParameter::time_step(const double input)			{time_step_ = input;};
void MDParameter::time_length(const double input)		{time_length_ = input;};

unsigned long MDParameter::N() const			{return N_;}
double MDParameter::epsilon() const				{return epsilon_;}
double MDParameter::sigma() const				{return sigma_;}
double MDParameter::m() const					{return m_;}
double MDParameter::boundary_width() const		{return boundary_width_;}
double MDParameter::time_step() const			{return time_step_;}
double MDParameter::time_length() const			{return time_length_;}

/** @brief Parse key-value parameter from input/input.txt
 *
 * @param[in] path Path to input.txt file 
 * @param[in] suffix Suffix of key-value pair file, default = ".txt" */
void MDParameter::read_input(const string& path, const string& suffix){
	cout << "entering read_para" << endl;

	string n = path + suffix;
	//const auto a = path.ends_with(suffix);
	//if (false == a){n += suffix;}

	ifstream f_in(n, ios::in);
	string line;
	if (f_in.is_open()){
		while (!f_in.eof()){
			while(getline(f_in, line)){
				vector<string> line_cutted;
				line_cutted = str_split(line, ':');
				string key = line_cutted[0];
				if (2 == line_cutted.size()){  // to avoid empty value field
					if (!key.compare("N")){				// TODO maybe use "case" is better
						N_ = stoul(line_cutted[1]);
						cout << "N:\t\t\t" << N_ <<endl;
					}
					if (!key.compare("epsilon")){
						epsilon_ = stold(line_cutted[1]);
						cout << "epsilon:\t\t" << epsilon_ <<endl;
					}
					if (!key.compare("sigma")){
						sigma_ = stoi(line_cutted[1]);
						cout << "sigma:\t\t\t" << sigma_ <<endl;
					}
					if (!key.compare("m")){
						m_ = stod(line_cutted[1]);
						cout << "m:\t\t\t" << m_ <<endl;
					}
					if (!key.compare("boundary_width")){
						boundary_width_ = stoi(line_cutted[1]);
						cout << "periodic boundary width:\t" << boundary_width_ <<endl;
					}
				}
			}
		}
	}
	else{cout << "MDParameter::read_input: File could not be opened, path " << n << endl;}
	cout << "leaving read_input" << endl;
}

