#include "RPN.hpp"

bool Rpn::extraChars(char c){
	if (c != '+' && c != '-' 
		&& c != '*' && c != '/' && c != ' ' 
		&& (c < 0 || c >  9))
			return (true);
	return (false);
}

void Rpn::checkSynt(const std::string &expr){
	if (expr.size() < 5 || (expr[expr.size() - 1] >= 0 && expr[expr.size() - 1] <= 9))
	for (int i = 0; i < expr.size(); i++){
		if (extraChars(expr[i]))
			throw (std::invalid_argument("Extra Character"));
	}
}

void Rpn::createExp(){
	
}

void Rpn::parser(const std::string &expr){
	int i = expr.size();
	try{
		checkSynt(expr);
	} catch (const std::invalid_argument &e){
		std::cout << e.what() << std::endl;
	}
	for (int i = 1; i <= expr.size(); i++){
		switch (expr[expr.size() - i]){
			case '+':
				createExp();
			case '-':
				createExp();
			case '*':
				createExp();
			case '/':
				createExp();
		}
	}
}
