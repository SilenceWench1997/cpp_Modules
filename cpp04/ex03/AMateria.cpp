#include "AMateria.hpp"

AMateria::AMateria(){
	std::cout << "AMateria Default constructor called" << std::endl;
	this->type = "amateria";
}

AMateria::AMateria(std::string const & type){
	std::cout << "AMateria string constructor called" << std::endl;
	this->type = type;
}

AMateria(const AMateria &ref){
	std::cout << "AMateria copy constructor called" << std::endl;
	type = ref.type;
}

AMateria::~AMateria(){
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria & AMateria::operator=(const AMateria &ref){
	std::cout << "AMateria '=' operator overload" std::endl;
	if(this == &ref){
		std::cout << "Same materia" << std::endl:
		return (*this);
	}
	type = ref.type;
	return (*this);
}

AMateria *AMateria::clone() const{
	AMateria *ret = new AMateria(this->tpye);
	return (ret);
}

void AMateria::use(ICharacter &target){
	if (type == "ice")
		std::cout << "* shoots an ice bolt at " << target.name << "*" std::endl;
	else if (type == "cure")
		std::cout << "* heals " << target.name << "'s wounds *" std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

