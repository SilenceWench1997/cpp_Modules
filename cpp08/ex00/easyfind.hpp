#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
bool easyfind(T &cont, int to_find){
	std::vector<int>::iterator it = std::find(cont.begin(), cont.end(), to_find);
	if (it != cont.end())
		return (true);
	throw (std::out_of_range("Could not find."));
}

#endif
