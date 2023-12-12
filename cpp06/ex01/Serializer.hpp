#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer{
private:
	Serializer();
	Serializer(const Serializer &ref);
	Serializer &operator=(const Serializer &ref);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
