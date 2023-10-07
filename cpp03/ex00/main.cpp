#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n------------------Constructing------------------" << std::endl;
	ClapTrap a;
	ClapTrap b("Cody");
	std::cout << "\n------------------Testing------------------" << std::endl;
	a.attack("some other robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	b.beRepaired(3);
	b.beRepaired(3);
	std::cout << "\n------------------Deconstructing------------------" << std::endl;
}
