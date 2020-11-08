#ifndef PARTICAL_HPP_
#define PARTICAL_HPP_

#include "additional.hpp"

class ParticleList{
	public:
		ParticleList();

		void x(const Vec input);
		void v(const Vec input);
		void f(const Vec input);

		Vec x() const;
		Vec v() const;
		Vec f() const;

		void AddPartical();//TODO this function can't work well



	private:
		struct Particle{
			Vec x_;
			Vec v_;
			Vec f_;
			Particle *next_{NULL};
		};

		Particle *head_;
		Particle *curr_;

};


#endif