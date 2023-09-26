#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zed = new Zombie(name);
	return (zed);
}