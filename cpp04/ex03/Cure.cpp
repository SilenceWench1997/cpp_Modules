#include "Cure.hpp"

Cure::Cure(){
	std::cout << "Cure default constructor called" << std::endl;
	this->type = "cure";
}

Cure::~Cure(){
	std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(const Cure &ref){
	std::cout << "Cure copy constructor called" << std::endl;
	type = ref.type;
}

Cure & Cure::operator=(const Cure &ref){
	std::cout << "Cure '=' operator overload" << std::endl;
	if (this == &ref)
	{
		std::cout << "Same Cure" << std::endl;
		return (*this);
	}
	type = ref.type;
	return (*this);
}

void Cure::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure *Cure::clone() const{
	Cure *clone = new Cure;
	return (clone);
}