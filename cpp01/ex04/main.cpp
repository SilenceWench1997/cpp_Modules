#include <string>
#include <iostream>
#include <fstream>

std::string	replace(std::string text, std::string to_find, std::string replace)
{
	size_t		old_pos = 0;
	size_t		new_pos = 0;
	std::string	tmp;

	new_pos = text.find(to_find, 0);
	if (new_pos == std::string::npos){
		tmp = text;
		return (tmp);
	}
	tmp = text.substr(0, new_pos);
	tmp = tmp + replace;
	while (text.find(to_find, new_pos + to_find.size()) != std::string::npos){
		old_pos = new_pos;
		new_pos = text.find(to_find, new_pos + to_find.size());
		tmp = tmp + text.substr(old_pos + to_find.size(), new_pos - (old_pos + to_find.size()));
		tmp = tmp + replace;
	}
	tmp = tmp + text.substr(new_pos + to_find.size());
	return (tmp);
}

int main(int argc, char **argv)
{
	std::string 	text;
	std::string		filename;
	std::ofstream	replaceFile;
	char		a;

	if (argc == 4)
	{
		std::ifstream file(argv[1]);
		if (!file.is_open()){
			std::cerr << "Error: Can't open the file" << std::endl;
			return (1);
		}
		while (file.get(a)){
			text = text + a;
		}
		file.close();
		text = replace(text, argv[2], argv[3]);
		filename = argv[1];
		filename = filename + ".replace";
		replaceFile.open(filename);
		replaceFile << text << std::flush;
	}
	return (0);
}