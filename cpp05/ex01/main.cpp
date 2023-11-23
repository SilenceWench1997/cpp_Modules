#include "Bureaucrat.hpp"

int main(){
	Bureaucrat bur("test", 2);
	Form f("form", 0, 151, 4);
	try{
		bur.signForm(f);
	}
	catch (const Form::GradeTooLowException &e){
		std::cout << "Exception caught: " << e.what() <<std::endl;
	}
}