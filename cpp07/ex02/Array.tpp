#include "Array.hpp"

template<typename T>
Array<T>::Array() : elemArr(NULL), arrSize(0){
}

template<typename T>
Array<T>::Array(unsigned int n) : elemArr(new T[n]()), arrSize(n){
}

template<typename T>
Array<T>::Array(const Array& ref) : elemArr(new T[ref.size()]()){
	if (*this == ref)
		return;
	for (size_t i = 0; i < ref.size(); i++){
		elemArr[i] = ref.elemArr[i];
	}
	arrSize = ref.size();
}

template<typename T>
Array<T> &Array<T>::operator=(const Array& ref){
	if (*this == ref)
		return (*this);
	delete[] elemArr;
	elemArr = new T[ref.size()];
	for (size_t i = 0; i < ref.size(); i++){
		elemArr[i] = ref.elemArr[i];
	}
	arrSize = ref.size();
	return (*this);
}

template<typename T>
Array<T>::~Array(){
	delete[] elemArr;
	arrSize = 0;
}

template<typename T>
T &Array<T>::operator[](int index) const{
	if ((size_t)index > arrSize - 1){
		throw(std::out_of_range("invalid index"));
	}
	return (elemArr[index]);
}

template<typename T>
size_t Array<T>::size() const{
	return (arrSize);
}

template<typename T>
bool Array<T>::operator==(const Array &ref){
	if (arrSize == ref.size()){
		for (size_t i = 0; i < arrSize; i++){
			if (elemArr[i] != ref[i])
				return (false);
		}
		return (true);
	}
	return (false);
}

template<typename T>
void Array<T>::printMembers(void){
	for (size_t i = 0; i < size(); i++){
		std::cout << (*this)[i];
		if (i < size() - 1)
			std::cout << ", ";
	}
	std::cout << std::endl;
}
