#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc == 1){
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}else {
			PM conv;
			for (int i = 1; i < argc; i++){
					try{
						conv.parse(argv[i]);
					}catch (const std::invalid_argument &e){
						std::cout << e.what() << std::endl;
						return (0);
					}
			}
			conv.setStart();
			conv.sortV(conv.getArrV());
			conv.printResults(conv.getArrV(), conv.sortV(conv.getArrV()));
	}
	return (0);
}
