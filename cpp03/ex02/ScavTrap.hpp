#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string Name);
	ScavTrap(const ScavTrap &src);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap &src);
	void	attack();
	void	guardGate();
};