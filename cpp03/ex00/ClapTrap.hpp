#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
private:
	std::string Name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;
public:
	ClapTrap();
	ClapTrap(const std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap& operator=(const ClapTrap &src);
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif