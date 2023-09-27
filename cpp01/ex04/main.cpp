#include <string>
#include <iostream>
#include <fstream>

std::string	replace(std::string text, std::string to_find, std::string replace);

int main(int argc, char **argv)
{
	std::string 	text;
	std::string		filename;
	std::ofstream	replaceFile;

	if (argc == 4)
	{
		std::ifstream file(argv[1]);
		if (!file.is_open()){
			std::cerr << "Error: Can't open the file" << std::endl;
			return (1);
		}
		getline(file, text, '\0');
		file.close();
		text = replace(text, argv[2], argv[3]);
		filename = argv[1];
		filename = filename + ".replace";
		replaceFile.open(filename);
		replaceFile << text << std::flush;
	}
	return (0);
}