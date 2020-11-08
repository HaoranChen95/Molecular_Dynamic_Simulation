#include "partical.hpp"

using namespace std;

ParticleList::ParticleList(){
	head_ = NULL;
	curr_ = NULL;
}

void ParticleList::x(const Vec input)	{curr_ -> x_ = input;}
void ParticleList::v(const Vec input)	{curr_ -> v_ = input;}
void ParticleList::f(const Vec input)	{curr_ -> f_ = input;}

Vec ParticleList::x() const	{return curr_ -> x_;}
Vec ParticleList::v() const	{return curr_ -> v_;}
Vec ParticleList::f() const	{return curr_ -> f_;}

void ParticleList::AddPartical(){
	Particle *new_particle = new Particle;
	if(head_ != NULL){
		curr_ = head_;
		while (curr_ ->next_!= NULL) {
			curr_ = curr_ -> next_;
		}
		curr_ -> next_ = new_particle;
	}
	else{
		head_ = new_particle;
		curr_ = new_particle;
	}
}