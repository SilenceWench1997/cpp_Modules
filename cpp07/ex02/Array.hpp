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
	~Array();
	T &operator[](int index) const;
	bool operator==(const Array &ref);
	size_t size() const;
	void printMembers();
};

#endif
