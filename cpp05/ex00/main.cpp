#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat bur("test", 151);
		std::cout << bur << std::flush;
	}
	catch(const Bureaucrat::gradeTooHighException& ex){
		std::cout << ex.what() << std::endl;
	}
	catch(const Bureaucrat::gradeTooLowException& ex){
		std::cout << ex.what() << std::endl;
	}
}