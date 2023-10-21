#include "AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout << "AAnimal Default Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src){
	std::cout << "AAnimal Copy Constructor called" << std::endl;
	this->type = src.type;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal Destructor called" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}

void	AAnimal::makeSound() const
{
	std::cout << "*Regular Aanimal noises*" << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal &ref){
	this->type = ref.type;
	return (*this);
}
