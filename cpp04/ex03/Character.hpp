#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character : public ICharacter{
private:
	std::string name;
	AMateria *inv;
public:
	Character();
	Character(std::string name);
	Character(const Character &ref);
	~Character();
	Character &operator=(const Character &ref);
};

#endif