#include "assign.hpp"
using namespace std;
/** @brief Assigning input arguments from shell script start.sh
 *
 * Input arguments are assigned to global MDParamter object.
 *
 * @param[in] para input MDParameter class to get timestep
 * @param[in] argc Number of input arguments
 * @param[in] argv Input arguments **/
void assign(MDParameter& para, const unsigned argc, const char* argv[]) {
  cout << "entering assign" << endl;

  if (7 == argc) {
    para.lattice_edge_particles(stoul(argv[1]));
    para.time_length(stod(argv[2]));
    para.time_step(stod(argv[3]));
    para.scattering_time(stod(argv[4]));
    para.simple_alpha(stoi(argv[5]) != 0);
    para.open_nnl(stoi(argv[6]));
  } else {
    const string s =
        "Call executable with 4 input arguments \n lattice_edge_particles, \t "
        "time length, \t time step, \t scattering time, \t simple alpha, \t open nnl";
    throw(runtime_error(s));
  }

  cout << "leaving assign" << endl;
}
