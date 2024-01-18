#include "RPN.hpp"

bool Rpn::extraChars(char c){
	if (c != '+' && c != '-'
		&& c != '*' && c != '/' && c != ' ' 
		&& !isdigit(c))
			return (true);
	return (false);
}

void Rpn::checkSynt(const std::string &expr){
	for (size_t i = 0; i < expr.size(); i++){
		if (extraChars(expr[i]))
			throw (std::invalid_argument("Extra Character"));
		else if (isdigit(expr[i]) && isdigit(expr[i + 1]))
			throw (std::invalid_argument("Only single digit numbers are allowed"));
	}
}

void Rpn::doAction(char op){
	if (st.size() == 1)
		throw std::invalid_argument("Invalid Expression");
	int num2 = st.top();
	st.pop();
	int num1 = st.top();
	st.pop();
	switch (op){
		case '+':
		st.push(num1 + num2);
		break ;
		case '-':
		st.push(num1 - num2);
		break ;
		case '*':
		st.push(num1 * num2);
		break ;
		case '/':
		st.push(num1 / num2);
		break ;
	}
}

void Rpn::parser(const std::string &expr){
	try{
		checkSynt(expr);
	} catch (const std::invalid_argument &e){
		std::cout << e.what() << std::endl;
		return ;
	}
	for (size_t i = 0; i < expr.size(); i++){
		try{
			switch (expr[i]){
				case '+':
					doAction('+');
					break ;
				case '-':
					doAction('-');
					break ;
				case '*':
					doAction('*');
					break ;
				case '/':
					doAction('/');
					break ;
				case ' ':
					continue;
				default:
					st.push(expr[i] - '0');
			}
		}catch (const std::invalid_argument &e){
				std::cout << e.what() << std::endl;
				return ;
		}
	}
	if (st.size() != 1)
		std::cout << "Invalid expression" << std::endl;
	else
		std::cout << st.top() << std::endl;
}
