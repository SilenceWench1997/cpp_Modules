#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void){
	int val = std::rand();
	switch (val % 3){
		case 0:
		std::cout << "generator: Randomly generating an object of type 'A'" << std::endl;
		return (new A);
		case 1:
		std::cout << "generator: Randomly generating an object of type 'B'" << std::endl;
		return (new B);
		case 2:
		std::cout << "generator: Randomly generating an object of type 'C'" << std::endl;
		return (new C);
	}
	return (new A);
}

void identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "identify: The pointer sent to identify was of type 'A'" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "identify: The pointer sent to identify was of type 'B'" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "identify: The pointer sent to identify was of type 'C'" << std::endl;
	else
		std::cout << "identify: Could not identify the pointer" << std::endl;
}

void identify(Base &p){
	try {
			dynamic_cast<A&>(p);
			std::cout << "identify: The reference sent to identify was of type 'A'" << std::endl;
			return ;
	} catch (std::exception &e) {}
	try {
			dynamic_cast<B&>(p);
			std::cout << "identify: The reference sent to identify was of type 'B'" << std::endl;
			return ;
	} catch (std::exception &e) {}
	try {
			dynamic_cast<C&>(p);
			std::cout << "identify: The reference sent to identify was of type 'C'" << std::endl;
			return ;
	} catch (std::exception &e) {}
	std::cout << "identfy: could not identify the reference" << std::endl;
}
