#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
public:
	Dog();
	Dog(const Dog &src);
	~Dog();
	void makeSound() const;
	Dog &operator=(const Dog &ref);
};

#endif