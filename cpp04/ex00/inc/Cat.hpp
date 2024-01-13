#pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal{
	private:
		std::string	type;
	public:
		Cat();
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);
		
		void makeSound() const;
		std::string	getType() const;
};

std::ostream	&operator<<(std::ostream &stream, const Cat &instance);

#endif
