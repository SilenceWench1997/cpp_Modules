#ifndef HUMANA_HPP
#define HUMANA_HPP


#include <iostream>
#include "Weapon.hpp"

class HumanA{
	std::string	name;
	Weapon	gun;
public:
	void	attack();
	HumanA(std::string name, Weapon gun);
	~HumanA();
};

#endif