#include "velocity_verlet.hpp"
using namespace std;


void velocity_verlet_x(ParticleList *p_l, const MDParameter parm){
	// p_l[0].head();
	// p_l[1].head();
	// while(!p_l[0].is_end()){
	// 	p_l[1].x(periodic_coordinate(p_l[0].x() + p_l[0].v()*parm.time_step() + p_l[0].f()/2.0/parm.m()*pow(parm.time_step(),2),parm));
	// 	p_l[0].next();
	// 	p_l[1].next();
	// }
}

void velocity_verlet_v(ParticleList *p_l, const MDParameter parm){
	p_l[0].head();
	p_l[1].head();
	while(!p_l[0].is_end()){
		p_l[1].v(p_l[0].v()+(p_l[0].f()+p_l[1].f())/2.0/parm.m()*parm.time_step());
		p_l[0].next();
		p_l[1].next();
	}
}