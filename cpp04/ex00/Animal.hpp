#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &src);
	virtual ~Animal();
};

#endif