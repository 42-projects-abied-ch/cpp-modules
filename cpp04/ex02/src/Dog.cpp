/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:43:53 by abied-ch          #+#    #+#             */
/*   Updated: 2024/01/19 19:44:50 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

#include <iostream>

Dog::Dog() : type("Dog"), brain(new Brain){
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other){
	this->type = other.type;
	this->brain = new Brain(*other.getBrain());
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &other){
	this->type = other.type;
	this->brain = new Brain(*other.brain);
	std::cout << "Dog assignation operator called" << std::endl;
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
