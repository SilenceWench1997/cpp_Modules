#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>

class Rpn{
private:
	std::stack<double> st;
	void checkSynt(const std::string &expr);
	bool extraChars(char c);
	void doAction(char op);
public:
	void parser(const std::string &expr);
};

#endif
