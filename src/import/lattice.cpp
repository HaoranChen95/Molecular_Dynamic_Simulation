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
				cout << p_l[0].x() << endl;
				if (k + 1  == parm.lattice_edge_particles()){
					if (j + 1  == parm.lattice_edge_particles()){
						if (i + 1  == parm.lattice_edge_particles()){
							// TODO there still not clear
						}
					}
					else{
						for (unsigned long l; l+1 < parm.lattice_edge_particles(); ++l){
						temp[2] = 0;}
						p_l[0].v(temp);
					}
				}
				else{
					p_l[0].v(temp);
				}
			}
		}
	}
}
