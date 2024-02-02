#include "../inc/Fixed.hpp"

int Fixed::getRawBits() const{
    std::cout << "getRawBits mamber function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(const int raw){
	this->fixedPointValue = raw;
}

Fixed::Fixed(){
	this->fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

/* copy constructor: calling this constructor with an object of the same class 
as argument copies all the data members of the argument into the object being constructed */
Fixed::Fixed(Fixed const&src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/* assignation operator: called when '=' is used between two objects
to set the data members of the objedct being assigned to to the same values as the ones
from the source*/
Fixed&Fixed::operator=(Fixed const&rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(rhs.getRawBits());
	return *this;
}