#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>{
private:

public:
	MutantStack();
	MutantStack(const MutantStack &ref);
	~MutantStack();
	MutantStack &operator=(const MutantStack &ref);

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin();
	iterator end();
};