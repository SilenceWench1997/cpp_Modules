#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapREF): _Weapon(weapREF)
{
	this->name = name;
	std::cout << "HumanA " << name << " was created with " << weapREF.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << this->name << " was destroyed" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->_Weapon.getType() << std::endl;
}