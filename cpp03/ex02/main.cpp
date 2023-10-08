#include "FragTrap.hpp"

int main()
{
	std::cout << "\n-----------------Constructing-----------------" << std::endl;
	ClapTrap *e = new FragTrap("asdfasdf");
	FragTrap c;
	FragTrap a = c;
	std::cout << "\n-----------------Testing-----------------" << std::endl;
	e->attack("trasda");
	e->takeDamage(101);
	e->takeDamage(1);
	e->attack("asdasd");
	std::cout << "\n-----------------Deconstructing-----------------" << std::endl;
	delete e;
	return (0);
}