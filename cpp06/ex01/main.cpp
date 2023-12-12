#include "Data.hpp"
#include "Serializer.hpp"

int main(void){
	Data *ptr = new Data;
	
	ptr->price = 5000;
	ptr->type = "vodka";

	std::cout << "Before:\ntype: " << ptr->type << "\nprice: " << ptr->price << std::endl;
	ptr = Serializer::deserialize(Serializer::serialize(ptr));
	std::cout << "After:\ntype: " << ptr->type << "\nprice: " << ptr->price << std::endl;


	std::cout << "DON'T FORGET TO CHANGE THE STANDARD FLAG IN MAKEFILE" << std::endl;
}
