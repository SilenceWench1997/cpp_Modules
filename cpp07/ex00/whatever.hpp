#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>

void swap(T &i, T &j){
	T a = i;
	i = j;
	j = a;
}

template <typename T>

T &min(T &i, T &j){
	if (i == j)
		return (j);
	else if (i < j)
		return (i);
	else
		return (j);
}

template <typename T>

T max(T i, T j){
	if (i == j)
		return (j);
	else if (i < j)
		return (j);
	else
		return (i);
}

#endif
