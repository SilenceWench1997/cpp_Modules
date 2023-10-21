#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Dog basic;
	
	std::cout << std::endl;
	{
		Dog tmp;
		tmp = basic;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	Cat basic2;
	{
		Cat tmp = basic2;
	}
	std::cout << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	const AAnimal	*Aanimal_array[4];
	std::cout << std::endl;
	// Half with dogs
	for (int i = 0; i < 2; i++)
		Aanimal_array[i] = new Dog();
	std::cout << std::endl;

	// Half with cats
	for (int i = 2; i < 4; i++)
		Aanimal_array[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete Aanimal_array[i];
	system("leaks animal");
    return 0;
}