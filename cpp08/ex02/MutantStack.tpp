#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &ref){
	this = &ref;
}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &ref){
	if(this != &ref)
		this = &ref;
	return (*this);
}