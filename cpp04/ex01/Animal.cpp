#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &src){
	std::cout << "Animal Copy Constructor called" << std::endl;
	this->type = src.type;
}

Animal::~Animal(){
	std::cout << "Animal Destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
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