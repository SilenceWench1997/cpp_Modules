#include "Bezdna.hpp"

int Bezdna::size = 0;

AMateria **Bezdna::ptrArr = new AMateria*[1];

void Bezdna::printBezdna(){
	std::cout << "-------------------Bezdna-------------------" << std::endl;
	for (int i = 0; i < size; i++){
		std::cout << ptrArr[i]->getType() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
}

AMateria **Bezdna::newArr(AMateria **ptrArr, AMateria *materia){
	AMateria **toReturn = new AMateria*[size + 1];

	for (int i = 0; i < size; i++){
		toReturn[i] = ptrArr[i];
		ptrArr[i] = NULL;
	}
	toReturn[size] = materia;
	delete[] ptrArr;
	return (toReturn);
}

void Bezdna::throwToBezdna(AMateria *materia){
	if (size == 0)
	{
		ptrArr[size] = materia;
		size++;
	}
	else {
		ptrArr = newArr(ptrArr, materia);
		size++;
	}
}