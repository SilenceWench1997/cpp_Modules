#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const AAnimal &src);
	virtual ~AAnimal();
	virtual std::string getType() const;
	virtual void makeSound() const = 0;
	AAnimal &operator=(const AAnimal &ref);
};

#endif