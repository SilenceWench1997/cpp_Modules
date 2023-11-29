#include "Bureaucrat.hpp"

int main(){
	Bureaucrat bur("test", 141);
	Form f("form", 0, 140, 4);
	try{
		bur.signForm(f);
	}
	catch (const Form::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what() <<std::endl;
	}
}