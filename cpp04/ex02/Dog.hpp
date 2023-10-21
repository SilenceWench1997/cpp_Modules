#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog &src);
	~Dog();
	void makeSound() const;
	Dog &operator=(const Dog &ref);
};

#endif