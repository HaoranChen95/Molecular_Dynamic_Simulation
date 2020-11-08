#include "velocity_verlet.hpp"

void sum_force(ParticleList p_l, double (*force)(const double r)){
	p_l.head();
	while (!p_l.is_end()){
		Vec temp_f {Vec::Zero(3)};
		p_l.set_temp();
		p_l.next();
		
		while (true){}; // todo need to change
		
	}

}

void velocity_verlet_x(ParticleList *p_l, const MDParameter parm){
	p_l[0].head();
	p_l[1].head();
	while(!p_l[0].is_end()){  //TODO maybe should change to for loop
		p_l[1].x(p_l[0].x() + p_l[0].v()*parm.time_step() + p_l[0].f()/2.0/parm.m()*pow(parm.time_step(),2));
	}
}

void velocity_verlet_v(ParticleList *p_l, const MDParameter parm){
	p_l[0].head();
	p_l[1].head();
	while(!p_l[0].is_end()){
		p_l[1].v(p_l[0].v()+(p_l[0].f()+p_l[1].f())/2.0/parm.m()*parm.time_step());
	}

}