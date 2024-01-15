#pragma once

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
	Animal &operator=(const Animal &other);
	
	virtual std::string	getType() const;
	virtual void makeSound() const;
};

std::ostream	&operator<<( std::ostream &stream, const Animal &instance );

#endif