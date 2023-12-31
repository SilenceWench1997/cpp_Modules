#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource Default Constructor called" << std::endl;
	for(int i = 0; i < 4; i++){
		this->materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &ref){
	std::cout << "MateriaSource Copy Constructor called" << std::endl;
	for (int i = 0; i < 4; i++){
		this->materias[i] = ref.materias[i];
	}
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++){
		if (materias[i])
			delete (materias[i]);
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource &ref){
	if (this == &ref)
	{
		std::cout << "Same MateriaSource" << std::endl;
		return (*this);
	}
	for (int i = 0; i < 4; i++){
		this->materias[i] = ref.materias[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *ptr){
	std::cout << "MateriaSource is learning " << ptr->getType() << std::endl;
	for (int i = 0; i < 4; i++){
		if (!this->materias[i])
		{
			this->materias[i] = ptr;
			return ;
		}
	}
	std::cout << "Failed to learn materia";
}

AMateria *MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		std::cout << i << " " << this->materias[i]->getType() << std::endl;
		if (this->materias[i] && this->materias[i]->getType() == type){
			return(this->materias[i]->clone());
		}
	}
	std::cout << "Here" << std::endl;
	return (0);
}