#ifndef WEAPON_HPP
#define WEAPON_HPP

class	Weapon{
	std::string	type;
public:
	Weapon(std::string name);
	~Weapon();
	const std::string&	getType();
	void	setType(std::string	set);
};

#endif