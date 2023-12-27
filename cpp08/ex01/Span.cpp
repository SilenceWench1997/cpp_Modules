#include "Span.hpp"

Span::Span() : N(3), size(0), arr(new int[3]){
}

Span::Span(unsigned int N) : N(N), size(0), arr(new int[N]){
}

Span::Span(const Span &ref) : N(ref.getN()),size(ref.getSize()), arr(new int[ref.getN()]){
	for (size_t i = 0; i < ref.getSize(); i++){
		arr[i] = ref.arr[i];
	}
}

Span &Span::operator=(const Span &ref){
	if (this != &ref){
		delete[] (ref.arr);
		N = ref.getN();
		for(size_t i = 0; i < ref.getSize(); i++){
			arr[i] = ref.arr[i];
		}
		size = ref.getSize();
	}
	return (*this);
}

Span::~Span(){
	delete[] (arr);
}

unsigned int Span::getN() const{
	return (N);
}

size_t Span::getSize() const{
	return (size);
}

void Span::addNumber(int num){
	if (size == N)
		throw std::out_of_range("Array is full!");
	arr[size++] = num;
}

size_t Span::shortestSpan() const{	
	size_t span;
	if (size <= 1)
		throw std::length_error("Less than two members, no span.");
	span = abs(arr[0] - arr[1]);
	for (size_t i = 0; i < size - 1; i++){
		if (static_cast<size_t>(abs(arr[i] - arr[i + 1])) < span){
			span = abs(arr[i] - arr[i + 1]);
		}
	}
	return (span);
}

size_t Span::longestSpan() const{	
	size_t span;
	if (size <= 1)
		throw std::length_error("Less than two members, no span.");
	span = abs(arr[0] - arr[1]);
	for (size_t i = 0; i < size - 1; i++){
		if (static_cast<size_t>(abs(arr[i] - arr[i + 1])) > span){
			span = abs(arr[i] - arr[i + 1]);
		}
	}
	return (span);
}


