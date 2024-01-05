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

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
	return (this->c.end());
}