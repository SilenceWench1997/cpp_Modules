#ifndef BEZDNA_HPP
# define BEZDNA_HPP

#include "AMateria.hpp"

class Bezdna{
	private:
		static int 	size;
		static AMateria **ptrArr;
	public:
		static void throwToBezdna(AMateria *materia);
		static AMateria ** newArr(AMateria **ptrArr, AMateria *materia);
		static void	printBezdna();
};


#endif