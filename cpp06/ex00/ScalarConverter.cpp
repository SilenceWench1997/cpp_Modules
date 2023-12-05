#include "ScalarConverter.hpp"

bool intCheck(std::string str){
	try{
		std::stoi(str);
	}catch(const std::invalid_argument &e){
		return (false);
	}catch(const std::out_of_range &e){
		return (false);
	}
	return (true);
}

bool charCheck(std::string str){
	if (str.length() != 3 || str[0] != '\'' || str[2] != '\'')
		return (false);
	return (true);
}

bool doubleCheck(std::string str){
	try{
		std::stod(str);
	}catch(const std::invalid_argument &e){
		return (false);
	}catch(const std::out_of_range &e){
		return (false);
	}
	return (true);
}

bool floatCheck(std::string str){
	try{
		std::stof(str);
	}catch(const std::invalid_argument &e){
		return (false);
	}catch(const std::out_of_range &e){
		return (false);
	}
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
	try {
		switch(figureType(literal)){
			case INT:
				toInt(literal);
			case CHAR:
				toChar(literal);
			case DOUBLE:
				toDouble(literal);
			case FLOAT:
				toFloat(literal);
		}
	}
//	catch (const ScalarConverter::impossibleException &e){
//		std::cout << e.what() << std::endl;
//	}
}
