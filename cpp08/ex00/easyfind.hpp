#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
int easyfind(T &cont, int to_find){
	for(int i = 0; cont[i]; i++){
		if (cont[i] == to_find)
			return i;
	}
	throw (std::out_of_range("Could not find."));
}

#endif
