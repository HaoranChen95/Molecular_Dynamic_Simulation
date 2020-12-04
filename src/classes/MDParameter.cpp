/** @class
 *
 *
 */
#include "MDParameter.hpp"
using namespace std;

MDParameter::MDParameter(){
	// m_	=	1.0;
	// epsilon_ = 1.0;
	// sigma_ = 1.0;

	// lattice_edge_particles_ = 4;
	// N_ = lattice_edge_particles_ * lattice_edge_particles_ * lattice_edge_particles_;

	// density_ = 0.5;
	// lattice_constant_ = pow(density_, -1.0/3.0);
	// boundary_width_ = lattice_edge_particles_ * lattice_constant_;

	// kT_ = 1.0;
}

void MDParameter::print(){
	cout << "===========================================" <<endl;
	cout << "m:\t\t\t\t" << m_ << endl;
	cout << "epsilon:\t\t\t" << epsilon_ << endl;
	cout << "sigma:\t\t\t\t" << sigma_ << endl;
	cout << "-------------------------------------------" <<endl;
	cout << "lattice_edge_particles:\t\t" << lattice_edge_particles_<< endl;
	cout << "N:\t\t\t\t" << N_ << endl;
	cout << "density:\t\t\t" << density_ << endl;
	cout << "lattice constant:\t\t" << lattice_constant_ << endl;
	cout << "boundary width:\t\t\t" << boundary_width_ << endl;
	cout << "kT:\t\t\t\t" << kT_ << endl;
	cout << "nearest neighbor radius:\t" << neighbor_ << endl;
	cout << "-------------------------------------------" <<endl;
	cout << "time length:\t\t\t" << time_length_ << endl;
	cout << "time step:\t\t\t" << time_step_ << endl;
	cout << "scattering time:\t\t" << scattering_time_ << endl;
	cout << "open nearest neighbor list:\t" << open_nnl_ << endl;
	cout << "===========================================" <<endl;
}

void MDParameter::N(const unsigned long input)			{N_ = input;};
void MDParameter::lattice_edge_particles(const unsigned long input){lattice_edge_particles_ = input;
																	N_ = input * input * input;}
void MDParameter::epsilon(const double input)			{epsilon_ = input;};
void MDParameter::sigma(const double input)				{sigma_ = input;};
void MDParameter::m(const double input)					{m_ = input;};
void MDParameter::boundary_width(const double input)	{boundary_width_ = input;};
void MDParameter::time_step(const double input)			{time_step_ = input;};
void MDParameter::time_length(const double input)		{time_length_ = input;};
void MDParameter::scattering_time(const double input)	{scattering_time_ = input;}
void MDParameter::open_nnl(const bool input)			{open_nnl_ = input;}

unsigned long MDParameter::N() const			{return N_;}
unsigned long MDParameter::lattice_edge_particles() const {return lattice_edge_particles_;}
double MDParameter::epsilon() const				{return epsilon_;}
double MDParameter::sigma() const				{return sigma_;}
double MDParameter::m() const					{return m_;}
double MDParameter::boundary_width() const		{return boundary_width_;}
double MDParameter::time_step() const			{return time_step_;}
double MDParameter::time_length() const			{return time_length_;}
double MDParameter::lattice_constant() const	{return lattice_constant_;}
double MDParameter::kT() const					{return kT_;}
double MDParameter::neighbor() const			{return neighbor_;}
double MDParameter::scattering_time() const		{return scattering_time_;}
bool MDParameter::open_nnl() const				{return open_nnl_;}

/** @brief Parse key-value parameter from input/input.txt
 *
 * @param[in] path Path to input.txt file 
 * @param[in] suffix Suffix of key-value pair file, default = ".txt" */
void MDParameter::read_input(const string& path, const string& suffix){
	// cout << "entering read_para" << endl;

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
					if (!key.compare("N")){
						N_ = stoul(line_cutted[1]);
						cout << "set N:\t\t\t" << N_ <<endl;
						cout << "===========================================" <<endl;
					}
					if (!key.compare("density")){
						density_ = stold(line_cutted[1]);
						lattice_constant_ = pow(density_, -1.0/3.0);
						boundary_width_ = lattice_edge_particles_ * lattice_constant_;
						cout << "set density:\t\t\t" << density_ <<endl;
						cout << "set lattice constant:\t\t" << lattice_constant_ <<endl;
						cout << "set boundary width:\t\t" << boundary_width_ << endl;
						cout << "===========================================" <<endl;
					}
					if (!key.compare("lattice_edge_particles")){
						lattice_edge_particles_ = stoul(line_cutted[1]);
						N_ = lattice_edge_particles_ * lattice_edge_particles_ * lattice_edge_particles_;
						boundary_width_ = lattice_edge_particles_ * lattice_constant_;
						cout << "set lattice_edge_particles\t" << lattice_edge_particles_<< endl;
						cout << "set N:\t\t\t\t" << N_ <<endl;
						cout << "set boundary width:\t\t" << boundary_width_ << endl;
						cout << "===========================================" <<endl;
					}
					if (!key.compare("epsilon")){
						epsilon_ = stold(line_cutted[1]);
						cout << "epsilon:\t\t\t" << epsilon_ <<endl;
						cout << "===========================================" <<endl;
					}
					if (!key.compare("sigma")){
						sigma_ = stoi(line_cutted[1]);
						cout << "set sigma:\t\t\t" << sigma_ <<endl;
						cout << "===========================================" <<endl;
					}
					if (!key.compare("m")){
						m_ = stod(line_cutted[1]);
						cout << "set m:\t\t\t\t" << m_ <<endl;
						cout << "===========================================" <<endl;
					}
					if (!key.compare("boundary_width")){
						boundary_width_ = stod(line_cutted[1]);
						cout << "set periodic boundary width:\t" << boundary_width_ <<endl;
						cout << "===========================================" <<endl;
					}
					if (!key.compare("kT")){
						kT_= stod(line_cutted[1]);
						cout << "set kT:\t\t\t\t" << kT_ <<endl;
						cout << "===========================================" <<endl;
					}
					if (!key.compare("neighbor")){
						neighbor_= stod(line_cutted[1]);
						cout << "set search neighbor radius:\t" << neighbor_ <<endl;
						cout << "===========================================" <<endl;
					}
					if (!key.compare("scattering_time")){
						scattering_time_ = stod(line_cutted[1]);
						cout << "set scattering time:\t\t" << scattering_time_ <<endl;
						cout << "===========================================" <<endl;
					}
					if (!key.compare("open_nnl")){
						open_nnl_ = stoi(line_cutted[1]) != 0;
						cout << "set open nearest neighbor list:\t" << open_nnl_ <<endl;
						cout << "===========================================" <<endl;
					}
				}
			}
		}
	}
	else{cout << "MDParameter::read_input: File could not be opened, path " << n << endl;}
	// cout << "leaving read_input" << endl;
}

