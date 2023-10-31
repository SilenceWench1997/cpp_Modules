#include "Character.hpp"
#include "Bezdna.hpp"


Character::Character() : name("default"), invCount(0){
	std::cout << "Character default constructor called" << std::endl;
	for(int i = 0; i < 4; i++){
		this->inv[i] = NULL;
	}
}

Character::Character(std::string name) : name(name), invCount(0){
	std::cout << "Character with name " << name << " is created" << std::endl;
	for(int i = 0; i < 4; i++){
		this->inv[i] = NULL;
	}
}

Character::Character(const Character &ref) : name(ref.name), invCount(0){
	std::cout << "Character " << name << " copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++){
		inv[i] = ref.inv[i];
	}
}

Character::~Character(){
	std::cout << "Character " << name << " destructor called" << std::endl;
	for (int i = 0; i < 4; i++){
		if (inv[i])
			delete (inv[i]);
	}
}

Character &Character::operator=(const Character &ref){
	std::cout << "Character '=' overload" << std::endl;
	if (this == &ref)
	{
		std::cout << "Same character" << std::endl;
		return (*this);
	}
	for (int i = 0; i < 4; i++){
		inv[i] = ref.inv[i];
	}
	return (*this);
}

std::string const & Character::getName() const{
	return (name);
}

void Character::equip(AMateria *m){
	std::cout << "Character " << name << " is trying to equip materia " << m->getType() << std::endl;
	for (int i = 0; i < 4; i++){
		if (!inv[i])
		{
			inv[i] = m;
			invCount++;
			std::cout << "Equiped successfully!" << std::endl;
			return ;
		}
	}
	std::cout << "Failed to equip" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0 || !inv[idx])
		std::cout << "Invalid index to unequip" << std::endl;
	else
	{
		std::cout << "Character " << name << " unequips materia " << inv[idx]->getType() << " and throws it to bezdna" << std::endl;
		Bezdna::throwToBezdna(inv[idx]);
		inv[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target){
	if (idx >= 4 || idx < 0 || !inv[idx])
		std::cout << "invalid index" << std::endl;
	inv[idx]->use(target);
}