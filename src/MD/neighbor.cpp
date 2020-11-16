#include "neighbor.hpp"

std::list<std::list<std::list<Particle>::const_iterator>> neighbor(const MDParameter parm, const std::list<Particle> p_l){
	std::list<std::list<std::list<Particle>::const_iterator>> part_pll;
	if (!p_l.empty()){
		std::list<Particle>::const_iterator part_l_iter;
		for (part_l_iter = p_l.begin(); part_l_iter != p_l.end(); part_l_iter++){
			std::list<std::list<Particle>::const_iterator> part_pl;
			part_pl.push_back(part_l_iter);//todo finish the part_pll
			std::list<Particle>::const_iterator another_part_l_iter;

			for (another_part_l_iter = p_l.begin(); another_part_l_iter != p_l.end(); another_part_l_iter++){
				double r{periodic_vector(parm, (*part_l_iter).q, (*another_part_l_iter).q).norm()};
				if( r < parm.neighbor() && r != 0){
					part_pl.push_back(part_l_iter);
				}
			part_pll.push_back(part_pl);
			}
		}
	}
	return part_pll;
}