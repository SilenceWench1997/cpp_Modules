#include "FragTrap.hpp"
int main()
{
	std::cout << "\n-----------------Constructing-----------------" << std::endl;
	FragTrap e("test");
	FragTrap f;
	f = e;
	std::cout << "\n-----------------Testing-----------------" << std::endl;
	e.highFiveGuys();
	e.attack();
	e.takeDamage(101);
	e.takeDamage(1);
	e.attack();
	f.highFiveGuys();
	std::cout << "\n-----------------Deconstructing-----------------" << std::endl;
	return (0);
}