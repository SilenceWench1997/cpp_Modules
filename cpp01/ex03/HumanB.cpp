#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name):_weapon(NULL)
{
	this->name = name;
	std::cout << "HumanB " << name << " created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB" << this->name << "destroyed" << std::endl;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapREF)
{
	this->_weapon = &weapREF;
}