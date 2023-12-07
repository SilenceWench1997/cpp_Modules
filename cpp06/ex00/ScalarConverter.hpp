#ifndef SC_CONV_HPP
#define SC_CONV_HPP

#include <iostream>
#include <sstream>

enum returnVal{
	INT = 0,
	CHAR = 1,
	FLOAT = 2,
	DOUBLE = 3,
};

class ScalarConverter{
private:
	std::string type;
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &ref);
	ScalarConverter &operator=(const ScalarConverter &ref);
	virtual ~ScalarConverter() = 0;
	
	static void convert(std::string literal);
};

#endif
