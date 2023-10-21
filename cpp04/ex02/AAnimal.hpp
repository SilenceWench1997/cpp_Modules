#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const AAnimal &src);
	virtual ~AAnimal() = 0;
	virtual std::string getType() const;
	virtual void makeSound() const;
	AAnimal &operator=(const AAnimal &ref);
};

#endif