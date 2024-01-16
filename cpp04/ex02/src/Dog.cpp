/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:43:53 by abied-ch          #+#    #+#             */
/*   Updated: 2024/01/13 17:14:44 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

#include <iostream>

Dog::Dog() : type("Dog"), brain(new Brain){
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other){
	this->brain = new Brain(*other.getBrain());
	this->type = other.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other){
	if (this->brain != NULL)
		delete this->brain;
	this->brain = new Brain;
	this->type = other.getType();
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Woof woof" << std::endl;
}

std::string Dog::getType() const{
	return this->type;
}

Brain *Dog::getBrain() const{
	return this->brain;
}

std::ostream	&operator<<( std::ostream &stream, const Dog & ){
	stream << "Dog: Woof Woof!" << std::endl;
	return (stream);
}
