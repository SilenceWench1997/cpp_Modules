#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zed = new Zombie(name);
	return (zed);
}

void	randomChump(std::string name)
{
	Zombie zed = Zombie(name);

	zed.announce();
}

int main()
{
	Zombie *zed = newZombie("test1");
	zed->announce();
	randomChump("test2");
	delete zed;
	return (0);
}