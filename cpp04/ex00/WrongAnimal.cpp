#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	this->type = src.type;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	if (this->type == "Dog")
	{
		std::cout << "Bark" << std::endl;
	}
	else if (this->type == "Cat")
	{
		std::cout << "Meow" << std::endl;
	}
}