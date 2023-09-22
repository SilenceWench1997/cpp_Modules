#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>

class HumanB{
	std::string	name;
	Weapon	gun;
public:
	void	attack();
	HumanB(std::string name);
	~HumanB();
};

#endif