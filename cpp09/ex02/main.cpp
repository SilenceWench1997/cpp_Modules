#include "PmergeMeV.hpp"
#include "PmergeMeL.hpp"

void	parse(std::string input, PMV &sortV, PML &sortL){
	std::istringstream conv(input);
	int num;

	for (size_t i = 0; i < input.size(); i++){
		if (!isdigit(input[i]))
			throw (std::invalid_argument("Non Numeric Character"));
	}
	if (!(conv >> num))
		throw (std::invalid_argument("Enter a number between 0 and 2147483647"));
	sortV.getArrV().push_back(num);
	sortL.getArrL().push_back(num);
}

int main(int argc, char **argv){
	if (argc == 1){
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}else {
			PMV sortV;
			PML sortL;
			for (int i = 1; i < argc; i++){
					try{
						parse(argv[i], sortV, sortL);
					}catch (const std::invalid_argument &e){
						std::cout << e.what() << std::endl;
						return (0);
					}
			}
			sortV.setStart();
			sortV.sortV(sortV.getArrV());
			sortL.sortL(sortL.getArrL());
			sortV.printResults(sortV.getArrV(), sortV.sortV(sortV.getArrV()));
	}
	return (0);
}
