#ifndef CURE_HPP
# define CURE_HPP

class Cure : public AMateria{
public:
	Cure();
	Cure(const Cure &ref);
	~Cure();
	Cure &operator=(const Cure &ref);
};

#endif