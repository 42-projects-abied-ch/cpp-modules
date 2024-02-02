/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:43:53 by abied-ch          #+#    #+#             */
/*   Updated: 2024/01/19 19:10:10 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

#include <iostream>

Animal::Animal() : type("Some kind of animal"){
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type){
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal Destructor called"	<< std::endl;
}

std::string Animal::getType(void) const{
	return (this->type);
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = other.type;
	return *this;
}

void Animal::makeSound() const{
	std::cout << "Some kind of animal makes a sound" << std::endl;
}

Brain *Animal::getBrain() const{
	return (NULL);
}

std::ostream	&operator<<(std::ostream &stream, const Animal &instance){
	stream << "Animal:"
		<< "type = " << instance.getType() << std::endl;
	return (stream);
}
