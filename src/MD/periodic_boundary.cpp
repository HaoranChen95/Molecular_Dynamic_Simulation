#include "periodic_boundary.hpp"

Vec periodic_force(const Vec x_a, const Vec x_b, double (*force)(const MDParameter parm, const double r), const MDParameter parm){
	Vec f{x_a - x_b};
	for (int i{0}; i<3; ++i){
		f[i] = remainder(f[i], parm.boundary_width());
	}
	f = force(parm, f.norm())/f.norm()*f;
	return f;
}

Vec periodic_boundary(const Vec x, const MDParameter parm){
	Vec n_x{Vec::Zero(3)};
	for (int i{0}; i<3; ++i){
		n_x[i] = remainder(x[i], parm.boundary_width());
		if(n_x[i] < 0){n_x[i] = n_x[i] + parm.boundary_width();}
	}
	return n_x;
}