#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string Name);
	ScavTrap(const ScavTrap &src);
	ScavTrap& operator=(const ScavTrap &src);
	~ScavTrap();
	void	attack();
	void	guardGate();
};

#endif