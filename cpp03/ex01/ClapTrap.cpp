#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : Name("test"), hitPoints(10), energyPoints(10), attackDamage(10)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : Name(name), hitPoints(10), energyPoints(10), attackDamage(10)
{
	std::cout << "ClapTrap Individual name constructor called" << std::endl; 
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;

	this->Name = src.Name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src){
	std::cout << "ClapTrap '=' operator overload" << std::endl;

	this->Name = src.Name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;

	return (*this);
}

void	ClapTrap::attack(const std::string &target){
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		return ;
	std::cout << "ClapTrap " << this->Name << " attacks " << target  << std::flush;
	std::cout << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->hitPoints <= 0)
		return ;
	std::cout << "ClapTrap " << this->Name << " took " << std::flush;
	std::cout << amount << " points of damage!" << std::endl;
	if (this->hitPoints - amount <= 0)
		std::cout << "ClapTrap " << this->Name << " is dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->energyPoints <= 0 || this->hitPoints <= 0)
		return ;
	std::cout << "ClapTrap " << this->Name << " gained " << std::flush;
	std::cout << amount << " hit points!" << std::endl;
	this->energyPoints--;
}