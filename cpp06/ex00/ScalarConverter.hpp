#ifndef SC_CONV_HPP
#define SC_CONV_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>

class ScalarConverter{
private:
	static int	intVal;
	static char	chVal;
	static double	doubVal;
	static float	flVal;
	enum ReturnVal{
		INT,
		CHAR,
		FLOAT,
		DOUBLE,
		PSEUDO,
	};
	enum Pseudos{
		NINFF,
		PINFF,
		NANF_,
		NINF,
		PINF,
		NAN_,
	};
	static Pseudos ps;
	ScalarConverter();
	ScalarConverter(const ScalarConverter &ref);
	ScalarConverter &operator=(const ScalarConverter &ref);
	~ScalarConverter();
	class invalidInput : public std::exception{
	public:
		virtual const char *what() const throw(){
			return "Invalid input";
		} 
	};
	static int  figureType(const std::string &literal);
	static bool intCheck(const std::string &str);
	static bool charCheck(const std::string &str);
	static bool doubleCheck(const std::string &str);
	static bool floatCheck(const std::string &str);
	static bool pseudoCheck(const std::string &literal);
	static void caseInt(void);
	static void caseChar(void);
	static void caseDouble(void);
	static void caseFloat(void);
	static void casePseudo(void);
	static void printChar(double val);
	static void printInt(double val);
	static void printDouble(double val);
	static void printFloat(double val);
public:
	static void convert(const std::string &literal);

};

#endif
