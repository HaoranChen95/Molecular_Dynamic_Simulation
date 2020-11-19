#include "neighbor.hpp"

std::forward_list<std::forward_list<std::forward_list<Particle>::const_iterator>> neighbor(const MDParameter parm, const std::forward_list<Particle> p_l){
	std::forward_list<std::forward_list<std::forward_list<Particle>::const_iterator>> part_pll;
	if (!p_l.empty()){
		std::forward_list<Particle>::const_iterator part_l_iter;
		for (part_l_iter = p_l.begin(); part_l_iter != p_l.end(); part_l_iter++){
			std::forward_list<std::forward_list<Particle>::const_iterator> part_pl;
			part_pl.push_front(part_l_iter);//todo finish the part_pll
			std::forward_list<Particle>::const_iterator another_part_l_iter;

			for (another_part_l_iter = p_l.begin(); another_part_l_iter != p_l.end(); another_part_l_iter++){
				double r{periodic_vector(parm, (*part_l_iter).x, (*another_part_l_iter).x).norm()};
				if( r < parm.neighbor() && r != 0){
					part_pl.push_front(part_l_iter);
				}
			//part_pll.push_fr part_pl.push_front(part_pl);
			}
		}
	}
	return part_pll;
}