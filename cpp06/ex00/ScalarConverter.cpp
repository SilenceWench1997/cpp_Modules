#include "ScalarConverter.hpp"

bool intCheck(std::string str){
	std::istringstream conv(str);
	int intVal;
	if(conv >> intVal)
		;
	else
		return (false);
	
	for(long unsigned int i = 0 + (str[0] == '-'); i < str.length(); i++){
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	std::cout << "INT!" << std::endl;
	return (true);
}


bool charCheck(std::string str){
	if (str.length() != 3 || str[0] != '\'' || str[2] != '\'')
		return (false);
	std::cout << "CHAR!" << std::endl;
	return (true);
}

bool doubleCheck(std::string str){
	bool	dot;
	std::istringstream conv(str);
	double	doubVal;
	
	if (conv >> doubVal)
		;
	else
		return (false);
	for(long unsigned int i = 0 + (str[0] == '-'); i < str.length(); i++){
		if (str[i] < '0' || str[i] > '9'){
			if (str[i] == '.' && (i - (str[0] == '-')) != 0 && dot == false){
				dot = true;
				continue ;
			}
			return (false);
		}
	}
	std::cout << "DOUBLE!" << std::endl;
	return (true);
}

bool floatCheck(std::string str){
	bool dot = false;
	bool f = false;
	std::istringstream conv(str);
	float flVal;

	if (conv >> flVal)
		;
	else
		return (false);
	for(long unsigned int i = 0 + (str[0] == '-'); i < str.length(); i++){
		if (str[i] < '0' || str[i] > '9'){
			if (str[i] == '.' && (i - (str[0] == '-')) != 0 && dot == false){
				dot = true;
				continue ;
			}
			else if (str[i] == 'f' && (i + 1) == str.length() && f == false){
				f = true;
				continue ;
			}
			return (false);
		}
	}
	std::cout << "FLOAT!" << std::endl;	
	return (true);
}

int figureType(const std::string literal){
	if (intCheck(literal))
		return INT;
	else if (charCheck(literal))
		return CHAR;
	else if (doubleCheck(literal))
		return DOUBLE;
	else if (floatCheck(literal))
		return FLOAT;
//	else
//		throw (ScalarConverter::invalidInput());
	return (9);
}

void	toInt(std::string conv){
(void)conv;
}

void	toChar(std::string conv){
(void)conv;
}

void	toDouble(std::string conv){
(void)conv;
}

void	toFloat(std::string conv){
(void)conv;
}

void	ScalarConverter::convert(const std::string literal){
//	try {
		switch(figureType(literal)){
			case INT:
				toInt(literal);
				break ;
			case CHAR:
				toChar(literal);
				break ;
			case DOUBLE:
				toDouble(literal);
				break ;
			case FLOAT:
				toFloat(literal);
				break ;
		}
//	}
//	catch (const ScalarConverter::impossibleException &e){
//		std::cout << e.what() << std::endl;
//	}
}
