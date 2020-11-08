#ifndef PARTICAL_HPP_
#define PARTICAL_HPP_

#include "additional.hpp"

class ParticleList{
	public:
		ParticleList();
		
		void to_index(const unsigned int index);

		void x(const Vec input);
		void v(const Vec input);
		void f(const Vec input);

		Vec x() const;
		Vec v() const;
		Vec f() const;

		void AddPartical();//TODO this function can't work well

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
		Particle *curr_;

};


#endif