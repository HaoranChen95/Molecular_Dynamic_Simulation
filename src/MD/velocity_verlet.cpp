#include "velocity_verlet.hpp"
using namespace std;

void sum_force(ParticleList p_l, double (*force)(const MDParameter parm, const double r), MDParameter parm){
	p_l.head();
	while (!p_l.is_end()){
		p_l.set_temp();
		p_l.temp_f(Vec::Zero(3));
		p_l.next();
		cout << "in the outer loop" << endl;
		while (!p_l.is_self()){
			p_l.temp_f(p_l.temp_f() + periodic_force(p_l.temp_x(), p_l.x(), force, parm));
			cout << "temp_f is\n" << p_l.temp_f() << endl;
			p_l.next();
			if(p_l.is_end()) {p_l.head();}
		}; 
		p_l.next();
		cout << "Finished inner loop" <<endl;
	}
	cout << "Finished outer loop" <<endl;
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