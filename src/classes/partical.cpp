#include "partical.hpp"

Particle::Particle(){
	head_ = NULL;
	next_ = NULL;
}

void Particle::x(const Vec input)	{x_ = input;}
void Particle::v(const Vec input)	{v_ = input;}
void Particle::f(const Vec input)	{f_ = input;}

Vec Particle::x() const	{return x_;}
Vec Particle::v() const	{return v_;}
Vec Particle::f() const	{return f_;}

Particle Particle::next(){

}

Particle Particle::head(){

}

void Particle::AddPartical(){
	Particle *new_particle = new Particle;
	if(head_ != NULL){
		Particle *curr_particle;
		while (curr_particle == NULL) {
			curr_particle -> next_ = next_;
		}
		curr_particle -> next_ = new_particle;
	}
	else{
		head_ = new_particle;
	}
}