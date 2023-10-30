#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
	AMateria *materias[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &ref);
	~MateriaSource();
	MateriaSource & operator=(const MateriaSource &ref);
	void learnMateria(AMateria *ptr);
	AMateria *createMateria(std::string const & type);
};