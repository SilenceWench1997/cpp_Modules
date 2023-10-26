#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
	
public:
	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const & type);
};