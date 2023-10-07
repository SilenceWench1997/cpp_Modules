#include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
public:
	FragTrap();
	FragTrap(std::string Name);
	~FragTrap();
	FragTrap(const FragTrap &src);
	FragTrap& operator=(const FragTrap &src);
	void highFiveGuys(void);
};