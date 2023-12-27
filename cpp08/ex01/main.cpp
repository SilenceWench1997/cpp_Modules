#include "Span.hpp"

int main(){
	Span sp = Span(10000);
	try{
		std::cout << sp.longestSpan() << std::endl;
	}catch (const std::length_error &e){
		std::cout << e.what() << std::endl;
	}
	for (size_t i = 0; i < 10000 ;i++){
		sp.addNumber(i);
	}
	try{
		sp.addNumber(100000);
	}catch (const std::out_of_range &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
}

/*
int main(){
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}*/
