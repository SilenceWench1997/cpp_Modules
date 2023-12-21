#include "Array.tpp"

int main(){
		std::cout << "-----Construction With No Parameter----" << std::endl;
		Array<int> a;
		std::cout << "Size: " << a.size() << "\n";
		std::cout << "---------------------------------------" << std::endl;

		std::cout << "\n-----Construction With an Unsigned Int as a Parameter----\n";
		Array<float> c(32);
		std::cout << "Size: " << c.size() << "\n";
		std::cout << "\nAccessing the array members through [] operator:\n";
		for (size_t i = 0; i < c.size(); i++){
			if (i % 3 == 0)
				c[i] = i * 3.14;
			std::cout << c[i];
			if (i < c.size() - 1)
				std::cout << ", ";
		}
		std::cout << "\nIf the index is out of bounds, it throws std::exception" << std::endl;
		try{
				c[c.size()];
		}catch(const std::exception &e){
				std::cout << e.what() << std::endl;
		}
		std::cout << "---------------------------------------------------------" << std::endl;

		std::cout << "Check Leaks bruh" << std::endl;
}
