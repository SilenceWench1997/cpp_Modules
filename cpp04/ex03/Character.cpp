#include "Character.hpp"

Character::Character() : name("char"), inv(new AMateria[4]){
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name){
	std::cout << "Character with name " << name << " is created" << std::endl;
	inv = new AMateria[4];
	this->name = name;
}

Character::Character(const Character &ref){
	std::cout << "Character " << name << " copy constructor called" << std::endl;
	name = ref.name;
	inv = new AMateria[4];
	for (int i = 0; i < 4; i++){
		inv[i] = ref.inv[i];
	}
}

Character::~Character(){
	std::cout << "Character " << name << " destructor called" << std::endl;
	delete[] inv;
}

Character &Character::operator=(const Character &ref){
	std::cout << "Character '=' overload" << std::endl;
	if (this = &ref)
	{
		std::cout << "Same character" << std::endl;
		return (*this);
	}
	delete[] inv;
	inv = new AMateria[4];
	for (int i = 0; i < 4; i++){
		inv[i] = ref.inv[i];
	}
	return (*this);
}

std::string const & Character::getName() const{
	return (name);
}

void Character::equip(AMateria *m){
	std::cout << "Character" << name << "equips materia" << std::endl;
	for (int i = 0; i < 4; i++){
		if (!inv[i])
			inv[i] = *m;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
		std::cout << "invalid index" << std::endl;
	else
	{
		std::cout << "Character" << name << "unequips materia" << std::endl;
		
	}
}

void Character::use(int idx, ICharacter &target){
	if (idx >= 4 || idx < 0 || !inv[idx])
		std::cout << "invalid index" << std::endl;
	
}