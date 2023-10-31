#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Bezdna.hpp"

void	run()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void run2()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	delete bob;
	delete me;
	delete src;
	Character a;
	{
		Character b("b");
		a = b;
	}
	{
		Character c(a);
	}
	{
		Character d("d");
		a = d;
	}
}

void run3()
{
	Character a("test");
	AMateria *test1 = new Ice();
	AMateria *test2 = new Ice();
	AMateria *test3 = new Ice();
	AMateria *test4 = new Cure();
	AMateria *test5 = new Cure();
	a.equip(test1);
	a.equip(test2);
	a.equip(test3);
	a.equip(test4);
	a.equip(test5);
	a.unequip(1);
	a.unequip(2);
	a.unequip(3);
	a.unequip(1);
	a.equip(test5);
	// Bezdna::printBezdna();
}

int main()
{
	// run();
	// run2();
	run3();
	// system("leaks ex03");
	return 0;
}