#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>

class AAnimal{
protected:
	std::string	type;
public:
	AAnimal();
	AAnimal(const AAnimal &other);
	virtual ~AAnimal();
	AAnimal &operator=(const AAnimal &other);
	
	virtual std::string	getType() const;
	virtual void		makeSound() const;
	virtual Brain		*getBrain() const = 0;
};

#endif