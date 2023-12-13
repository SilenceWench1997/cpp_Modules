#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "functions.hpp"

//CHECK FOR LEAKS!!!

int main(){
	Base *ptr;

	for (int i = 0; i < 20; i++){
		std::cout << "------------------Object number " << i << "----------------------" <<std::endl;
		ptr = generate();
		std::cout << "\nPointer:" << std::endl;
		identify(ptr);
		std::cout << "\nReference:" << std::endl;
		identify(*ptr);
		std::cout << "---------------------------------------------------------" << std::endl;
		std::cout << "\n";
		delete ptr;
	}
}
