#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	std::cout << "Zombie object " << " was created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie object " << this->name << " was destroyed" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
