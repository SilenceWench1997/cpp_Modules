#include "Span.hpp"

Span::Span() : size(0), N(3){
}

Span::Span(unsigned int n) : size(0), N(n){
}

Span::Span(const Span &ref) : size(ref.getSize()), N(ref.getN()){
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

void	Span::range(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	if (size + std::distance(begin, end) > N)
		throw std::out_of_range("Array does not have enough space");
	while (begin != end){
		arr.push_back(*begin);
		begin++;
		size++;
	}
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
	std::vector<int> vt = arr;
	size_t temp = abs(vt[0] - vt[1]);
	std::sort(vt.begin(), vt.end());
	for (size_t i = 0; i < size - 1; i++){
		if (temp > (size_t)abs(vt[i] - vt[i + 1]))
			temp = abs(vt[i] - vt[i + 1]);
	}
	return (temp);
}

size_t Span::longestSpan() const{
	if (size <= 1)
		throw std::length_error("Less than two members, no span.");
	return (abs(*std::max_element(arr.begin(), arr.end()) - *std::min_element(arr.begin(), arr.end())));
}

Span::~Span(){
}

unsigned int Span::getN() const{
	return (N);
}

size_t Span::getSize() const{
	return (size);
}
