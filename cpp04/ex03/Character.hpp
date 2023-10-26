#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter{
private:
	std::string name;
	AMateria *inv;
public:
	Character();
	Character(std::string name);
	Character(const Character &ref);
	~Character();
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	std::string const & getName() const;
	Character &operator=(const Character &ref);
};

#endif