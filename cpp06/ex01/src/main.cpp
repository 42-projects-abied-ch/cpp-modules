#include "../inc/Serializer.hpp"
#include <stdint.h>

int main()
{
	t_DataStructure	*data = new t_DataStructure;
	data->fullName = "Arthur Bied-Charreton";
	data->birthDate = "30.03.2001";
	data->day = 30;
	data->month = 3;
	data->year = 2001;

	std::cout << "Data Structure Before Deserialization:" << std::endl << std::endl;
	std::cout << "Full Name:\t\t["<< data->fullName << "]" << std::endl;
	std::cout << "Birth Date:\t\t["<< data->birthDate << "]" << std::endl;
	std::cout << "Birth Day:\t\t["<< data->day << "]" << std::endl;
	std::cout << "Birth Month:\t\t["<< data->month << "]" << std::endl;
	std::cout << "Birth Year:\t\t["<< data->year << "]" << std::endl << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	std::cout << "Raw uintptr_t:\t\t[" << raw << "]" << std::endl << std::endl;
	t_DataStructure *deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized Pointer:\t[" << deserialized << "]" << std::endl << std::endl;

	std::cout << "Data Structure After Deserialization:" << std::endl << std::endl;
	std::cout << "Full Name:\t\t["<< deserialized->fullName << "]" << std::endl;
	std::cout << "Birth Date:\t\t["<< deserialized->birthDate << "]" << std::endl;
	std::cout << "Birth Day:\t\t["<< deserialized->day << "]" << std::endl;
	std::cout << "Birth Month:\t\t["<< deserialized->month << "]" << std::endl;
	std::cout << "Birth Year:\t\t["<< deserialized->year << "]" << std::endl;

	delete data;
}