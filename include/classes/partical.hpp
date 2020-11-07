#ifndef PARTICAL_HPP_
#define PARTICAL_HPP_

#include "additional.hpp"

class Particle{
	public:
		Particle();
		
		void x(const Vec input);
		void v(const Vec input);
		void f(const Vec input);

		Vec x() const;
		Vec v() const;
		Vec f() const;

		Particle next(); //TODO need to define.
		Particle head();

		void AddPartical();//TODO this function can't work well



	private:
		Vec x_;
		Vec v_;
		Vec f_;
		Particle *head_;
		Particle *curr_;
		Particle *next_;
};


#endif