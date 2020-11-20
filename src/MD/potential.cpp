#include "potential.hpp"

using namespace std;
/**
 * @brief the difine of LJ potential and Force Field
 * 
 * @param[in] para the global parameter of MD simulation
 * @param[in] r the radius to the center of partical
 * @return double 
 */

double Cut_LJ_Potential(const MDParameter parm, const Vec x_a, const Vec x_b){
	double r{periodic_vector(parm, x_a, x_b).norm()};
	if (r > pow(2.0,1/6)*parm.sigma() || r == 0){return 0.0;}
	return 4.0*parm.epsilon()*(pow((parm.sigma()/r),12)-pow((parm.sigma()/r),6))+parm.epsilon();
}

Vec Cut_LJ_Force(const MDParameter parm, const Vec x_a, const Vec x_b){
	cout << "in the cut LJ force, input\n " << x_a << endl << x_b << endl;
	Vec r {periodic_vector(parm, x_a, x_b)};
	double norm_r = r.norm();
	if (norm_r > pow(2.0,1/6)*parm.sigma() || norm_r == 0){return Vec::Zero(3);}
	else{
		cout << -r/norm_r*4.0*parm.epsilon()*(12*pow(parm.sigma(),12)/pow(norm_r,13)-6*pow(parm.sigma(),6)/pow(norm_r,7)) << endl;
		return -r/norm_r*4.0*parm.epsilon()*(12*pow(parm.sigma(),12)/pow(norm_r,13)-6*pow(parm.sigma(),6)/pow(norm_r,7));}
}