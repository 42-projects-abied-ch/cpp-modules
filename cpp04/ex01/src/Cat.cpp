/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:43:53 by abied-ch          #+#    #+#             */
/*   Updated: 2024/01/13 17:16:14 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

#include <iostream>

Cat::Cat() : type("Cat"), brain(new Brain){
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other){
	this->brain = new Brain(*other.getBrain());
	this->type = other.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain;
	this->type = other.type;
	std::cout << "Cat assignation operator called" << std::endl;
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meow meow" << std::endl;
}

std::string Cat::getType() const{
	return this->type;
}

Brain *Cat::getBrain() const{
	return this->brain;
}

std::ostream	&operator<<( std::ostream &stream, const Cat & ) {
	stream << "Cat: Meow Meow!" << std::endl;
	return stream;
}
