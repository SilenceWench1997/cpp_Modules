#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
	Zombie *zed = zombieHorde("test");
	delete zed;
	return (0);
}