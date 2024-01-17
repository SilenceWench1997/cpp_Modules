#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>

enum e_ops{
	ADD,
	SUB,
	MULT,
	DIV,
}

class operation{
	int firstNum;
	int	secondNum;
	e_ops op;
};

class Rpn{
private:
	std::list exp;
public:
		void parser(std::string &expr);
};

#endif
