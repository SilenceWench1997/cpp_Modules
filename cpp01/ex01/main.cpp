#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
	int i = 5;
	Zombie *zed = zombieHorde(i, "test");
	for(int j = 0; j < i; j++)
		zed[j].announce();
	delete[] zed;
	return (0);
}
