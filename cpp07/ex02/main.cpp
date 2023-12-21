#include "Array.tpp"

int main(){
		Array<int> a(5);
		Array<int> b(50);

		b = a;
		std::cout << "Check Leaks bruh" << std::endl;
}
