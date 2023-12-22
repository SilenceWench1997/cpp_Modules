#include "Array.tpp"

int main(){
		std::cout << "-----Construction With No Parameter----" << std::endl;
		Array<const int> a(5);
		std::cout << "Size: " << a.size() << "\n";
		std::cout << "---------------------------------------" << std::endl;

		std::cout << "\n-----Construction With an Unsigned Int as a Parameter----\n";
		Array<float> c(12);
		std::cout << "Size: " << c.size() << "\n";
		c.printMembers();
		std::cout << "\nIf the index is out of bounds, it throws std::exception" << std::endl;
		try{
				c[c.size()];
		}catch(const std::exception &e){
				std::cout << e.what() << std::endl;
		}
		std::cout << "---------------------------------------------------------" << std::endl;

		std::cout << "\n-----Copy Constructor and Assignment operators:------\n";
		{
			Array<double> a(10);
			for (size_t i = 0; i < a.size(); i++){
				a[i] = (i%3) * 32;
			}
			Array<double> b(a);
			Array<double> c;
			c = a;
			std::cout << "a's members: ";
			a.printMembers();
			std::cout << "b's members: ";
			b.printMembers();
			std::cout << "c's members: ";
			c.printMembers();
		}
		std::cout << "-----------------------------------------------------" << std::endl;
		std::cout << "Check Leaks bruh" << std::endl;
}
