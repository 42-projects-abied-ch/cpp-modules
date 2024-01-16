/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:43:53 by abied-ch          #+#    #+#             */
/*   Updated: 2024/01/16 17:51:21 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal() : type("Some kind of AAnimal"){
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type){
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal Destructor called"	<< std::endl;
}

std::string AAnimal::getType(void) const{
	return (this->type);
}

AAnimal &AAnimal::operator=(const AAnimal &other){
	std::cout << "AAnimal assignation operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

void AAnimal::makeSound() const{
	std::cout << "Some kind of AAnimal makes a sound" << std::endl;
}

std::ostream	&operator<<(std::ostream &stream, const AAnimal &instance){
	stream << "AAnimal:"
		<< "type = " << instance.getType() << std::endl;
	return (stream);
}
