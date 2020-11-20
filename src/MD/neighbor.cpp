#include "neighbor.hpp"

using namespace std;

const forward_list<forward_list<const Particle*>> neighbor(const MDParameter parm, const ParticleList p_l){
	cout << "entering neighbor function"<< endl;
	forward_list<forward_list<const Particle*>> p_l_pll;
	if (!p_l.empty()){
		forward_list<const Particle*> p_l_pl;
		for (ParticleList::const_iterator p_l_ci {p_l.cbegin()}; p_l_ci != p_l.cend(); ++p_l_ci){
			p_l_pl.clear();
			for (ParticleList::const_iterator another_p_l_ci{p_l.cbegin()}; another_p_l_ci != p_l.cend(); ++another_p_l_ci){
				if (p_l_ci == another_p_l_ci){continue;}
				else if( periodic_vector(parm, (*p_l_ci).x, (*another_p_l_ci).x).norm() < parm.neighbor()){
					p_l_pl.push_front(&(*another_p_l_ci));
				}
			}
			p_l_pl.push_front(&(*p_l_ci));
			p_l_pll.push_front(p_l_pl);
		}
		p_l_pll.reverse();
	}
	cout << "ending neighbor function"<< endl;
	return p_l_pll;
}

const forward_list<forward_list<const Particle*>> all_nodes(const MDParameter parm, const ParticleList p_l){
	forward_list<forward_list<const Particle*>> p_l_pll;
	if (!p_l.empty()){
		forward_list<const Particle*> p_l_pl;
		for (ParticleList::const_iterator p_l_ci {p_l.cbegin()}; p_l_ci != p_l.cend(); ++p_l_ci){
			p_l_pl.clear();
			for (ParticleList::const_iterator another_p_l_ci{p_l.cbegin()}; another_p_l_ci != p_l.cend(); ++another_p_l_ci){
				if (p_l_ci == another_p_l_ci){continue;}
				else {
					p_l_pl.push_front(&(*another_p_l_ci));
				}
			}
			p_l_pl.push_front(&(*p_l_ci));
			p_l_pll.push_front(p_l_pl);
		}
		p_l_pll.reverse();
	}
	return p_l_pll;
}