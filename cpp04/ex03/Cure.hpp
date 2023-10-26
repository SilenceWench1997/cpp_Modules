#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria{
public:
	Cure();
	Cure(const Cure &ref);
	~Cure();
	Cure &operator=(const Cure &ref);
	void use(ICharacter &target);
	Cure *clone() const;
};

#endif