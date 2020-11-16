#include "potential.hpp"

/**
 * @brief the difine of LJ potential and Force Field
 * 
 * @param[in] para the global parameter of MD simulation
 * @param[in] r the radius to the center of partical
 * @return double 
 */

double LJ_Potential(const MDParameter parm, const double r){
	if (r > pow(2.0,1/6)*parm.sigma()){return 0.0;}
	return 4.0*parm.epsilon()*(pow((parm.sigma()/r),12)-pow((parm.sigma()/r),6))+parm.epsilon();
}

double LJ_Force(const MDParameter para, const double r){ //TODO return to vector
	return 4.0*para.epsilon()*(12*pow(para.sigma(),12)/pow(r,13)-6*pow(para.sigma(),6)/pow(r,7));
}


