#include "neighbor.hpp"

std::list<std::list<Particle*>> neighbor(const MDParameter parm, const std::list<Particle> p_l){
	std::list<std::list<Particle*>> part_pll;
	if (!p_l.empty()){
		std::list<Particle>::const_iterator p_l_iter;
		for (p_l_iter = p_l.begin(); p_l_iter != p_l.end(); p_l_iter++){
			p_l_iter;//todo finish the part_pll
		}

		std::list<Particle*> part_pl;
	}
	return part_pll;
}