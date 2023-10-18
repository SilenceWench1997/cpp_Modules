#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* j = new Dog();
	Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	system("leaks animal");
	return 0;
}