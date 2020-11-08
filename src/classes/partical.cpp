#include "partical.hpp"

using namespace std;

ParticleList::ParticleList(){
	head_old_ = NULL;
	head_new_ = NULL; // TODO still need to improve the new particle list
	curr_old_ = NULL;
	curr_new_ = NULL;
}

void ParticleList::x_old(const Vec input)	{curr_old_ -> x_ = input;}
void ParticleList::v_old(const Vec input)	{curr_old_ -> v_ = input;}
void ParticleList::f_old(const Vec input)	{curr_old_ -> f_ = input;}
void ParticleList::x_new(const Vec input)	{curr_new_ -> x_ = input;}
void ParticleList::v_new(const Vec input)	{curr_new_ -> v_ = input;}
void ParticleList::f_new(const Vec input)	{curr_new_ -> f_ = input;}

Vec ParticleList::x() const	{return curr_old_ -> x_;}
Vec ParticleList::v() const	{return curr_old_ -> v_;}
Vec ParticleList::f() const	{return curr_old_ -> f_;}

void ParticleList::head()		{curr_old_ = head_old_; curr_new_ = head_new_;}
void ParticleList::next()		{curr_old_ = curr_old_ -> next_; curr_new_ = curr_new_ -> next_;}

void ParticleList::to_index(const unsigned long int index){
	if (head_old_ != NULL){
		head();
		int i{0};
		while(i < index && curr_old_ -> next_ != NULL){
			++i;
			next();
		}
		cout << "turn to index No. " << i << endl;
	}
}

void ParticleList::PrintList_x(){
	curr_old_ = head_old_;
	while (curr_old_ != NULL){
		cout << curr_old_ -> x_ << endl;
		curr_old_ = curr_old_ -> next_;
	}
	head();
}

void ParticleList::AddPartical(){
	Particle *new_particle_old = new Particle;
	Particle *new_particle_new = new Particle;
	new_particle_new -> next_ = NULL;
	new_particle_old -> next_ = NULL;

	if(head_old_ != NULL){
		head();
		while (curr_old_ -> next_ != NULL) {
			next();
		}
		curr_old_ -> next_ = new_particle_old;
		curr_new_ -> next_ = new_particle_new;
		cout << "creat new next Partical" << endl;
	}
	else{
		head_old_ = new_particle_old;
		head_new_ = new_particle_new;
		cout << "creat new head Partical" << endl;
	}
	curr_old_ = new_particle_old;
	curr_new_ = new_particle_new;
}