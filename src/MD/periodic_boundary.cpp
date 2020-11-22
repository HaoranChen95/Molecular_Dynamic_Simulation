#include "periodic_boundary.hpp"

Vec periodic_vector(const MDParameter parm, const Vec q_a, const Vec q_b){
	Vec vec{q_b - q_a};
	if (vec == Vec::Zero(3)) {return vec;}
	for (int i{0}; i<3; ++i){
		vec[i] = remainder(vec[i], parm.boundary_width());
	}
	return vec;
}

Vec periodic_coordinate(const MDParameter parm, const Vec q){
	Vec n_q{Vec::Zero(3)};
	for (int i{0}; i<3; ++i){
		n_q[i] = remainder(q[i], parm.boundary_width());
		if(n_q[i] < 0){n_q[i] += parm.boundary_width();}
	}
	return n_q;
}