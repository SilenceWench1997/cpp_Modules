#ifndef ICE_HPP
# define ICE_HPP

class Ice : public AMateria{
public:
	Ice();
	Ice(const Ice &ref);
	~Ice();
	Ice &operator=(const Ice &ref);
};

#endif