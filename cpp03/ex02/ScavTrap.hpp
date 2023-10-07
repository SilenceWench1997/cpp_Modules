#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string Name);
	ScavTrap(const ScavTrap &src);
	~ScavTrap();
	void	attack();
	void	guardGate();
};