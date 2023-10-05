#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap test0;
	ClapTrap test1("SomeName");
	ClapTrap test2(test0);
	ClapTrap test3 = test1;

	test0.attack("Bull");
	test1.takeDamage(3);
	test1.takeDamage(7);
	test1.attack("asd");
	test1.beRepaired(45);
	
}
