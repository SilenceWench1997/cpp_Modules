#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat &src);
	~Cat();
	void makeSound() const;
	Cat & operator=(const Cat &ref);
};

#endif