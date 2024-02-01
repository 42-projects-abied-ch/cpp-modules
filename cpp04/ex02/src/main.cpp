#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include <iostream>
#include "../inc/macros.h"

void	subjectMain(){
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;
}

void	assignationOperator(){
	const AAnimal *cat = new Cat();
	Cat *cat1 = new Cat();
	AAnimal *cat2 = new Cat();
	Cat *cat4 = new Cat();
	*cat4 = *cat1;
	std::cout << BOLDGREEN << "\nIDEAS\n" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << cat->getType() << " " << cat4->getBrain()->getIdeas()[i] << std::endl;
	std::cout << std::endl;
	delete cat;
	delete cat1;
	delete cat2;
	delete cat4;
}

void	copyConstructor(){
	Dog *doggo = new Dog();
	Dog cat3(*doggo);
	std::cout << BOLDGREEN << "\nCOPIED IDEAS\n" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << cat3.getType() << " " << cat3.getBrain()->getIdeas()[i] << std::endl;
	delete doggo;
}

void	animalArray(){
	const AAnimal *(animal_array[4]);
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		delete animal_array[i];
}

int main(){
	std::cout << BOLDREDUNDERLINE << "\nASSIGNATION OPERATOR\n" << RESET << std::endl;
	assignationOperator();
	std::cout << BOLDREDUNDERLINE << "\nCOPY CONSTRUCTOR\n" << RESET << std::endl;
	copyConstructor();
	std::cout << BOLDREDUNDERLINE << "\nANIMAL ARRAY\n" << RESET << std::endl;
	animalArray();
	std::cout << BOLDREDUNDERLINE << "\nSUBJECT MAIN\n" << RESET << std::endl;
	subjectMain();
}
