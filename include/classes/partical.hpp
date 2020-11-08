#ifndef PARTICAL_HPP_
#define PARTICAL_HPP_

#include "additional.hpp"

class ParticleList{
	public:
		ParticleList();
		
		void to_index(const unsigned long int index);

		void x(const Vec input);
		void v(const Vec input);
		void f(const Vec input);

		Vec x() const;
		Vec v() const;
		Vec f() const;

		void AddPartical();

		void head();
		void next();
		void set_temp();
		bool is_end();
		bool is_self();

		void PrintList_x();

	private:
		struct Particle{
			Vec x_;
			Vec v_;
			Vec f_;
			Particle *next_;
		};

		Particle *head_;
		Particle *curr_;
		Particle *temp_;

};


#endif