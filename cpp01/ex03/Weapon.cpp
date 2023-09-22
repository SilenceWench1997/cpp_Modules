#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->type = name;
}

Weapon::~Weapon()
{
}

const std::string&		Weapon::getType()
{
	return(*this->type);
}

void	std::string	setType(std::string	set)
{
	this->type = set;
}