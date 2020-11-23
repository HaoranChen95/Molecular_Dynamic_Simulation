// #include <random>
// #include <forward_list>
// #include <iostream>
// #include "Eigen/Eigen"

// typedef Eigen::Matrix<double, Eigen::Dynamic, 1> Vec;

// using namespace std;

// struct Particle{
// 	Vec x;
// 	Vec v;
// 	Vec f0;
// 	Vec f1;
// };

// typedef std::forward_list<Particle> ParticleList;

// ParticleList init_lattice(const MDParameter parm);

// main(){
// 	ParticleList p_l;
// 	Particle p1;
// 	p1.x =  
// 	int i_test = 0;
// 	forward_list<const Particle*> p_pl; //TODO there is the problem!!!!
// 	cout << "the Particle list (positions):" << endl;
// 	for (const Particle p : p_l){
// 		cout << p.x << endl;
// 		p_pl.push_front(&p);
// 		cout << "i_test " << i_test <<endl;
// 		++i_test;
// 		}

// 	i_test = 0;
// 	cout << "the Particle pointer list (positions):" << endl;
// 	for (const Particle* i : p_pl){cout << (*i).x << endl;
// 	cout << "i_test " << i_test <<endl;
// 	++i_test;
// 	}
// }
