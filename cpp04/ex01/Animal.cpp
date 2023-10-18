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
	std::cout << "*Regular animal noises*" << std::endl;
}

Animal & Animal::operator=(const Animal &ref){
	this->type = ref.type;
	return (*this);
}
