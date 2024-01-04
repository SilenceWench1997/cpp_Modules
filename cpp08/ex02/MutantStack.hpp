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

	T &top();
	bool empty();
	size_t size();
	void push(T elem);
	void pop();
};