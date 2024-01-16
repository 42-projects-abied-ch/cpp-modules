#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include <iostream>
#include "../inc/macros.h"

void	subjectMain(){
	std::cout << RED << "\nSUBJECT MAIN\n" << RESET << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}

int main(){
	// const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << RED << "\nIDEAS\n" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << cat->getType() << " " << cat->getBrain()->getIdeas()[i] << std::endl;
	std::cout << std::endl;
	const Animal *(animal_array[4]);
	std::cout << RED << "\nANIMAL ARRAY\n" << RESET << std::endl;
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	delete cat;
	std::cout << std::endl;
	subjectMain();
}