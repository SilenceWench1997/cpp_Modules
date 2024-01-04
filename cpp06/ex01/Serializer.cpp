#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &ref){*this = ref;}

Serializer &Serializer::operator=(const Serializer &ref){
	if (this == &ref)
		return *this;
	return *this;
}

Serializer::~Serializer(){}


uintptr_t Serializer::serialize(Data *ptr){
	uintptr_t raw;
	raw = reinterpret_cast<std::uintptr_t>(ptr);
	return (raw);
}

Data *Serializer::deserialize(uintptr_t raw){
	Data *ptr;
	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}
