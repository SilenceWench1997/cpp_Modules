#include "Span.hpp"

Span::Span() : N(3), size(0){
}

Span::Span(unsigned int N) : N(N), size(0){
}

Span::Span(const Span &ref) : N(ref.getN()),size(ref.getSize()){
	for (size_t i = 0; i < ref.getSize(); i++){
		arr[i] = ref.arr[i];
	}
}

Span &Span::operator=(const Span &ref){
	if (this != &ref){
		N = ref.getN();
		for(size_t i = 0; i < ref.getSize(); i++){
			arr[i] = ref.arr[i];
		}
		size = ref.getSize();
	}
	return (*this);
}

void Span::addNumber(int num){
	if (size == N)
		throw std::out_of_range("Array is full!");
	arr.push_back(num);
	size++;
}

size_t Span::shortestSpan() const{
	if (size <= 1)
		throw std::length_error("Less than two members, no span.");
	
}

size_t Span::longestSpan() const{
	if (size <= 1)
		throw std::length_error("Less than two members, no span.");
	return (std::max_element(arr.begin(), arr.end()) - std::min_element(arr.begin(), arr.end()));
}

Span::~Span(){
}

unsigned int Span::getN() const{
	return (N);
}

size_t Span::getSize() const{
	return (size);
}
