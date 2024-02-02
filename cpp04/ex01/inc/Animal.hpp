#pragma once

#include "Brain.hpp"
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal &other);
	virtual ~Animal();
	virtual Animal &operator=(const Animal &other);
	
	virtual std::string	getType() const;
	virtual void 		makeSound() const;
	virtual Brain		*getBrain() const;
};

std::ostream	&operator<<( std::ostream &stream, const Animal &instance );

#endif
