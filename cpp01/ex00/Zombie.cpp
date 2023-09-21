#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie object " << this->name << " was created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie object " << this->name << " was destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}