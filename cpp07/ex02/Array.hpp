#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<class T>
class Array{
private:
	T *elemArr;
	size_t arrSize;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &ref);
	Array &operator=(const Array &ref);
	T &operator[](int index);
	bool operator==(const Array &fst, const Array &scd);
	size_t size() const;
};

#endif
