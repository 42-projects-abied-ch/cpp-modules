/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:43:53 by abied-ch          #+#    #+#             */
/*   Updated: 2024/01/13 16:49:17 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

#include <iostream>

Dog::Dog() : type("Dog"){
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other){
	this->type = other.type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog&){
	std::cout << "Dog assignation operator called" << std::endl;
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Woof woof" << std::endl;
}

std::string Dog::getType() const{
	return (this->type);
}

std::ostream	&operator<<( std::ostream &stream, const Dog & ){
	stream << "Dog: Woof Woof!" << std::endl;
	return (stream);
}
