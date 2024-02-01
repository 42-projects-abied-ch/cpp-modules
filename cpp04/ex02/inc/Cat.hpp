#pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include <iostream>
#include "AAnimal.hpp"

class Cat : virtual public AAnimal{
	private:
		std::string	type;
		Brain		*brain;
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);
		
		void 				makeSound() const;
		std::string			getType() const;
		Brain				*getBrain() const;
};

std::ostream	&operator<<(std::ostream &stream, const Cat &instance);

#endif
