#include "Zombie.hpp"

Zombie* newZombie(std::string name);

void	randomChump(std::string name);

int main()
{
	Zombie *zed = newZombie("test1");
	zed->announce();
	randomChump("test2");
	delete (zed);
	return (0);
}