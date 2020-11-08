#ifndef PARTICAL_HPP_
#define PARTICAL_HPP_

#include "additional.hpp"

class ParticleList{
	public:
		ParticleList();
		
		void to_index(const unsigned long int index);

		void x_old(const Vec input);
		void v_old(const Vec input);
		void f_old(const Vec input);
		void x_new(const Vec input);
		void v_new(const Vec input);
		void f_new(const Vec input);

		Vec x() const;
		Vec v() const;
		Vec f() const;

		void AddPartical();

		void head();
		void next();

		void PrintList_x();

		

	private:
		struct Particle{
			Vec x_;
			Vec v_;
			Vec f_;
			Particle *next_;
		};

		Particle *head_old_;
		Particle *head_new_;
		Particle *curr_old_;
		Particle *curr_new_;

};


#endif