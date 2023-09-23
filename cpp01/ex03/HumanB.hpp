#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <string>
#include "Weapon.hpp"

class HumanB{
	std::string	name;
	Weapon	_Weapon;
public:
	void	attack();
	void	setWeapon(Weapon &weapREF);
	HumanB(std::string name);
	~HumanB();
};

#endif