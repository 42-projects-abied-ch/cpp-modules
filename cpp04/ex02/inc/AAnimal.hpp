#pragma once

#include "Brain.hpp"
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal{
protected:
	std::string	type;
public:
	AAnimal();
	AAnimal(const AAnimal &other);
	virtual ~AAnimal();
	virtual AAnimal &operator=(const AAnimal &other);
	
	virtual std::string	getType() const;
	virtual void 		makeSound() const;
	virtual Brain		*getBrain() const = 0;
};


#endif
