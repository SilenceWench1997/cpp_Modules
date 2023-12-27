#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void print(const T& pt){
	std::cout << pt << std::endl;
}

template <typename T>
void iter(T *arr, size_t length, void (*func)(const T&)){
	for (size_t i = 0; i < length; i++){
		func(arr[i]);
	}
}

template <typename T, typename G>
void iter(T *arr, size_t length, void (*func)(const G&)){
	for (size_t i = 0; i < length; i++){
		func(arr[i]);
	}
}

#endif
