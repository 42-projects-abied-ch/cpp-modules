#pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
	private:
		std::string	type;
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog &operator=(const Dog &other);

		void makeSound() const;
		std::string	getType() const;
};

std::ostream	&operator<<(std::ostream &stream, const Dog &instance);

#endif