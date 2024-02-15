#include "PmergeMeV.hpp"
#include "PmergeMeD.hpp"

void	printResults(std::vector<int> &before, std::vector<int> &after, double durationV, double durationD){
	std::cout << "Before: ";
	for (size_t i = 0; i < before.size(); i++)
		std::cout << before[i] << " ";
	std::cout << "\nAfter: ";
	for (size_t i = 0; i < after.size(); i++)
		std::cout << after[i] << " ";
	std::cout << "\nTime to process a range of " << before.size() << " elements with std::vector : " << std::fixed << durationV << " seconds";
	std::cout << "\nTime to process a range of " << before.size() << " elements with std::deque : " << std::fixed << durationD << " seconds" << std::endl;
}

void	parse(std::string input, PMV &sortV, PMD &sortD, std::vector<int> &before){
	std::istringstream conv(input);
	int num;

	for (size_t i = 0; i < input.size(); i++){
		if (!isdigit(input[i]))
			throw (std::invalid_argument("Non Numeric Character"));
	}
	if (!(conv >> num))
		throw (std::invalid_argument("Enter a number between 0 and 2147483647"));
	sortV.getArr().push_back(num);
	sortD.getArr().push_back(num);
	before.push_back(num);
}

int main(int argc, char **argv){
	if (argc == 1){
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}else {
			PMV sortV;
			PMD sortD;
			std::vector<int> before;
			std::vector<int> after;
			for (int i = 1; i < argc; i++){
				try{
					parse(argv[i], sortV, sortD, before);
				}catch (const std::invalid_argument &e){
					std::cout << e.what() << std::endl;
					return (0);
				}
			}
			after = sortV.sort(sortV.getArr());
			sortD.sort(sortD.getArr());
			printResults(before, after, sortV.getDuration(), sortD.getDuration());
	}
	return (0);
}
