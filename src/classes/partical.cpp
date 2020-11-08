#include "partical.hpp"

using namespace std;

ParticleList::ParticleList(){
	head_old_ = NULL;
	head_new_ = NULL; // TODO still need to improve the new particle list
	curr_ = NULL;
}

void ParticleList::x(const Vec input)	{curr_ -> x_ = input;}
void ParticleList::v(const Vec input)	{curr_ -> v_ = input;}
void ParticleList::f(const Vec input)	{curr_ -> f_ = input;}

Vec ParticleList::x() const	{return curr_ -> x_;}
Vec ParticleList::v() const	{return curr_ -> v_;}
Vec ParticleList::f() const	{return curr_ -> f_;}

void ParticleList::to_index(const unsigned int index){
	if (head_old_ != NULL){
		curr_ = head_old_;
		int i{0};
		while(i < index && curr_ -> next_ != NULL){
			++i;
			curr_ = curr_ -> next_;
		}
		cout << "turn to index No. " << i << endl;
	}
}

void ParticleList::PrintList_x(){
	curr_ = head_old_;
	while (curr_ != NULL){
		cout << curr_ -> x_ << endl;
		curr_ = curr_ -> next_;
	}
}

void ParticleList::AddPartical(){
	Particle *new_particle = new Particle;
	new_particle -> next_ = NULL;

	if(head_old_ != NULL){
		curr_ = head_old_;
		while (curr_ ->next_!= NULL) {
			curr_ = curr_ -> next_;
		}
		curr_ -> next_ = new_particle;
	}
	else{
		head_old_ = new_particle;
	}
	curr_ = new_particle;
}