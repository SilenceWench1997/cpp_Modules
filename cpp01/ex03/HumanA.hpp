#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA{
	std::string	name;
	Weapon	&_weapon;
public:
	void	attack();
	HumanA(std::string name, Weapon &weapREF);
	~HumanA();
};

#endif