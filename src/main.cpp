#include "main.hpp"

using namespace std;
/** @brief Main executable
 *
 * @param[in] argc Number of input arguments
 * @param[in] argv Input arguments **/

// TODO build a timer class
// TODO change the in put data class

int main(const int argc, const char* argv[]) {
  cout << "entering main" << endl;

  clock_t begin_time{clock()};

  try {
    assign(parm, argc, argv);
  } catch (const runtime_error& err) {
    cout << err.what() << endl;
    return 1;
  }

  parm.read_input();

  parm.print();

  // test_Cut_LJ_Potential(parm);

  // MD simulations goes here
  ParticlePtrList p_l{init_lattice(parm)};
  write_ParticleList(p_l);
  ParticlePtrList other_p_l{read_ParticleList()};
  write_ParticleList(other_p_l,"other_Particles");

  if (!p_l.empty()) {
    /** @brief print the p_l*/
    
    MD_Simulation(parm, p_l);
  }

  /** @brief out put program runing time */
  long int difftime{1000 * (clock() - begin_time) / CLOCKS_PER_SEC};
  long int diffmin{difftime / 60000};
  long int diffsec{(difftime % 60000) / 1000};
  long int diffmsec{difftime % 1000};
  cout << "leaving main, and used time: " << diffmin << " m " << diffsec
       << " s " << diffmsec << endl;
  return 0;
}
