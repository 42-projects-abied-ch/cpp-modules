/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:43:53 by abied-ch          #+#    #+#             */
/*   Updated: 2024/01/19 20:03:48 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal() : type("Some kind of animal"){
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type){
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << "Animal Destructor called"	<< std::endl;
}

std::string AAnimal::getType(void) const{
	return (this->type);
}

AAnimal &AAnimal::operator=(const AAnimal &other){
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = other.type;
	return *this;
}

void AAnimal::makeSound() const{
	std::cout << "Some kind of animal makes a sound" << std::endl;
}

Brain *AAnimal::getBrain() const{
	return (NULL);
}

std::ostream	&operator<<(std::ostream &stream, const AAnimal &instance){
	stream << "Animal:"
		<< "type = " << instance.getType() << std::endl;
	return (stream);
}
