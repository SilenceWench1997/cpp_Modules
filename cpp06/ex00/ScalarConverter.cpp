#include "ScalarConverter.hpp"

int ScalarConverter::intVal = 0;
char ScalarConverter::chVal = 0;
double ScalarConverter::doubVal = 0;
float ScalarConverter::flVal = 0;
ScalarConverter::Pseudos ScalarConverter::ps = ScalarConverter::NINFF;

ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(const ScalarConverter &ref){ *this = ref;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref){ *this = ref; return (*this);}

ScalarConverter::~ScalarConverter(){}

bool  ScalarConverter::intCheck(const std::string &str){
	std::istringstream conv(str);

	if(conv >> intVal)
		;
	else
		return (false);
	
	for(long unsigned int i = 0 + (str[0] == '-'); i < str.length(); i++){
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

bool  ScalarConverter::charCheck(const std::string &str){
	if (str.length() != 3 || str[0] != '\'' || str[2] != '\'')
		return (false);
	chVal = str[1];
	return (true);
}

bool  ScalarConverter::doubleCheck(const std::string &str){
	bool	dot;
	std::istringstream conv(str);
	
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
	return (true);
}

bool  ScalarConverter::floatCheck(const std::string &str){
	bool dot = false;
	bool f = false;
	std::istringstream conv(str);
	
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
	return (true);
}

bool ScalarConverter::pseudoCheck(const std::string &literal){
	std::string pseudos[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (int i = 0; i <= 5; i++){
		if (literal == pseudos[i]){
			ps = static_cast<Pseudos>(i);
			return (true);
		}
	}
	return (false);
}



int ScalarConverter::figureType(const std::string &literal){
	if (intCheck(literal))
		return INT;
	else if (charCheck(literal))
		return CHAR;
	else if (doubleCheck(literal))
		return DOUBLE;
	else if (floatCheck(literal))
		return FLOAT;
	else if (pseudoCheck(literal))
		return PSEUDO;
	else
		throw (ScalarConverter::invalidInput());
}

void	ScalarConverter::printChar(double val){
	if(val >= 32 && val <= 126)
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	else if ((val < 32 && val >= 0) || val == 127)
		std::cout << "char: " << "Non Displayable" << std::endl;
	else
		std::cout << "char: Impossible" << std::endl;
}

void	ScalarConverter::printDouble(double val){
	std::stringstream strstr;
	std::string	  result;
	
	strstr << val;
	result = strstr.str();
	if (val == -INFINITY || val == +INFINITY || result == "nan"){
		std::cout << "Double: " << val << std::endl;
		return ;
	}
	else if (result.find('e') == std::string::npos && result.find('.') == std::string::npos)
		std::cout << "Double: " << val << ".0"<< std::endl;
	else	
		std::cout << "Double: " <<val << std::endl;
}

void	ScalarConverter::printFloat(double val){
	std::stringstream strstr;
	std::string 	  result;

	strstr << val;
	result = strstr.str();
	if (flVal == -INFINITY || flVal == +INFINITY || result == "nan"){
			std::cout << "Floaat: " << val << "f" << std::endl;
			return ;
	}
	else if (val < -std::numeric_limits<float>::max()
	 || val > std::numeric_limits<float>::max()){
		std::cout << "Float: Impossible" << std::endl; 
		return ;
	}
	if (result.find('e') == std::string::npos && result.find('.') == std::string::npos)
		std::cout << "Float: " << static_cast<float>(val) << ".0f" << std::endl;
	else if (result.find('.') == std::string::npos)
		std::cout << "Float: " << static_cast<float>(val) << "f" << std::endl;
	else
		std::cout << "Float: " << static_cast<float>(val) << std::endl;
}

void	ScalarConverter::printInt(double val){
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		std::cout << "Int: Impossible" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(val) << std::endl;
}

void	ScalarConverter::caseInt(void){
	printChar(static_cast<double>(intVal));
	std::cout << "Int: " << intVal << std::endl;
	printDouble(static_cast<double>(intVal));
	printFloat(static_cast<float>(intVal));
}

void	 ScalarConverter::caseChar(void){
	std::cout << "Char: " << chVal << std::endl; 
	std::cout << "Int: " << static_cast<int>(chVal) << std::endl;
	std::cout << "Double: " << static_cast<double>(chVal) << ".0" <<std::endl;
	std::cout << "Float: " << static_cast<float>(chVal) << ".0f" << std::endl;
}

void	 ScalarConverter::caseDouble(void){
	printChar(doubVal);
	printInt(doubVal);
	printDouble(doubVal);
	printFloat(doubVal);
}

void	ScalarConverter::caseFloat(void){
	printChar(static_cast<double>(flVal));
	printInt(static_cast<double>(flVal));
	printDouble(static_cast<double>(flVal));
	printFloat(static_cast<double>(flVal));
}

void	ScalarConverter::casePseudo(void){
	switch(ps){
		case NINFF:
			flVal = -INFINITY;
			caseFloat();
			break ;
		case PINFF:
			flVal = +INFINITY;
			caseFloat();
			break ;
		case NANF_:
			flVal = NAN;
			caseFloat();
			break ;
		case NINF:
			doubVal = -INFINITY;
			caseDouble();
			break ;
		case PINF:
			doubVal = +INFINITY;
			caseDouble();
			break ;
		case NAN_:
			doubVal = NAN;
			caseDouble();
			break ;
	}
}

void	ScalarConverter::convert(const std::string &literal){
	try {
		switch(figureType(literal)){
			case INT:
				caseInt();
				break ;
			case CHAR:
				caseChar();
				break ;
			case DOUBLE:
				caseDouble();
				break ;
			case FLOAT:
				caseFloat();
				break ;
			case PSEUDO:
				casePseudo();
				break ;
		}
	}
	catch (const ScalarConverter::invalidInput &e){
		std::cout << e.what() << std::endl;
	}
}
