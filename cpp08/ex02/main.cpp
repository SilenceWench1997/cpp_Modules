#include "MutantStack.tpp"



int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		MutantStack<float> mstack;
		for (float i = 0; i < 42; i++){
			mstack.push(i);
		}
		MutantStack<float>::iterator itb = mstack.begin();
		MutantStack<float>::iterator ite = mstack.end();
		while (itb++ != ite){
			*itb = 42;
		}
		itb = mstack.begin();
		while (itb++ != ite){
			std::cout << *itb << std::endl;
		}
	}
	return 0;
}