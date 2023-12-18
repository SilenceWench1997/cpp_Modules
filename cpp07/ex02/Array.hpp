#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<class T>
class Array{
private:
	T *elemArr;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &ref);
	Array &operator=(const Array &ref);
	T &operator[](int index);
	size_t size();
};

#endif
