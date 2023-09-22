#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon gun)
{
	this->name = name;
	this->gun = gun;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->gun->getType();
}