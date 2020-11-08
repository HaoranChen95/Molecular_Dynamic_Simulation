#include "partical.hpp"

using namespace std;

ParticleList::ParticleList(){
	head_ = NULL;
	curr_ = NULL;
	temp_ = NULL;
}

void ParticleList::x(const Vec input)	{curr_ -> x_ = input;}
void ParticleList::v(const Vec input)	{curr_ -> v_ = input;}
void ParticleList::f(const Vec input)	{curr_ -> f_ = input;}

Vec ParticleList::x() const				{return curr_ -> x_;}
Vec ParticleList::v() const				{return curr_ -> v_;}
Vec ParticleList::f() const				{return curr_ -> f_;}

void ParticleList::head()				{curr_ = head_;}
void ParticleList::next()				{curr_ = curr_ -> next_;}

void ParticleList::set_temp()			{temp_ = curr_;}

bool ParticleList::is_end()					{return curr_-> next_ == NULL;}
bool ParticleList::is_self()				{return temp_ == curr_;}

void ParticleList::to_index(const unsigned long int index){
	if (head_ != NULL){
		head();
		int i{0};
		while(i < index && curr_ -> next_ != NULL){
			++i;
			next();
		}
		cout << "turn to index No. " << i << endl;
	}
}

void ParticleList::PrintList_x(){
	curr_ = head_;
	while (curr_ != NULL){
		cout << curr_ -> x_ << endl;
		curr_ = curr_ -> next_;
	}
	head();
}

void ParticleList::AddPartical(){
	Particle *new_particle = new Particle;
	new_particle -> next_ = NULL;

	if(head_ != NULL){
		head();
		while (curr_ -> next_ != NULL) {
			next();
		}
		curr_ -> next_ = new_particle;
		cout << "creat new next Partical" << endl;
	}
	else{
		head_ = new_particle;
		cout << "creat new head Partical" << endl;
	}
	curr_ = new_particle;
}