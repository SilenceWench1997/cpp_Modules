#ifndef SPAN_HPP
# define SPAN_HPP

class Span{
private:
	int *arr;
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
};

#endif
