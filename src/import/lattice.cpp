#include "lattice.hpp"
using namespace std;

void initial_lattice(ParticleList *p_l, const MDParameter parm)
{
	std::default_random_engine generator;
	std::normal_distribution<double> distribution(0,parm.kT());

	for (unsigned long i{0}; i < parm.lattice_edge_particles(); ++i){
		for (unsigned long j{0}; j < parm.lattice_edge_particles(); ++j){
			for (unsigned long k{0}; k < parm.lattice_edge_particles(); ++k){
				p_l[0].AddPartical();
				p_l[1].AddPartical();
				Vec temp{Vec::Zero(3)};
				temp[0]	= (i+0.5)*parm.lattice_constant();
				temp[1] = (j+0.5)*parm.lattice_constant();
				temp[2] = (k+0.5)*parm.lattice_constant();
				p_l[0].x(temp);

				temp[0]	= distribution(generator);
				temp[1] = distribution(generator);
				temp[2] = distribution(generator); 
				p_l[0].v(temp);
			}
		}
	}
}

void init_lattice(std::list<Particle>& p_l, const MDParameter parm){

}