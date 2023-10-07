#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\n------------------Constructing------------------" << std::endl;
	ScavTrap c("test");
	ScavTrap d;
	c = d;
	std::cout << "\n------------------Testing------------------" << std::endl;
	c.attack();
	c.beRepaired(22);
	c.takeDamage(21);
	c.beRepaired(22);
	c.guardGate();
	c.guardGate();
	d.attack();
	d.takeDamage(101);
	d.takeDamage(15);
	d.attack();
	std::cout << "\n------------------Deconstructing------------------" << std::endl;

}