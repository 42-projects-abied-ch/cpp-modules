#pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal{
	private:
		std::string	type;
		Brain		*brain;
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();
		Dog &operator = (const Dog &other);

		void 				makeSound() const;
		std::string			getType() const;
		Brain		*getBrain() const;
};

std::ostream	&operator<<(std::ostream &stream, const Dog &instance);

#endif