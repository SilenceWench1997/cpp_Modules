#include "Weapon.hpp"
#include <string>
#include <iostream>

Weapon::Weapon(std::string type): _type(type)
{
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType(void)
{
	return(this->_type);
}

void	Weapon::setType(std::string	set)
{
	this->_type = set;
}