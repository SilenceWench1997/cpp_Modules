#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <cstdlib>

class Span{
private:
	unsigned int N;
	size_t size;
	int	*arr;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &ref);
	Span &operator=(const Span &ref);
	~Span();
	unsigned int getN() const;
	size_t getSize() const;
	void addNumber(int num);
	size_t shortestSpan() const;
	size_t longestSpan() const;
};

#endif
