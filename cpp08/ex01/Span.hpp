#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span{
private:
	std::vector<int> arr;
	size_t size;
	unsigned int N;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &ref);
	~Span();
	Span &operator=(const Span &ref);
	void	addNumber(int number);
	size_t	shortestSpan() const;
	size_t	longestSpan() const;
	void	range(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	unsigned int getN() const;
	size_t getSize() const;
};

#endif