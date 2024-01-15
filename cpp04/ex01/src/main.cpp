#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include <iostream>

int main(){
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;
	delete dog;
	delete cat;
	std::cout << std::endl;
	std::cout << std::endl;
	Dog medor;
	Cat fifi;
	Dog & medor_ref = medor;
	Cat & fifi_ref = fifi;
	std::cout << "COPIES" << std::endl;
	Dog medor_copy(medor_ref);
	Cat fifi_copy(fifi_ref);
	std::cout << std::endl;
	const Animal	*(animal_array[4]);
	std::cout << std::endl;
	std::cout << "ANIMAL ARRAY" << std::endl;
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	std::cout << std::endl;
	system("leaks Brain");
}