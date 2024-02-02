#include "../inc/Fixed.hpp"
#include <ostream>

int Fixed::getRawBits() const{
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

Fixed::Fixed(Fixed const & src){
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int n){
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = n << this->fractionalBits;
}

Fixed::Fixed(float n){
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(n * (1 << this->fractionalBits));
}

// this converts the fixed point value to a float: the fractional part is divided by 2^fractionalBits (2^8 == 256)
// to get the decimal value of the fractional part
float Fixed::toFloat()const{
    return (float)this->fixedPointValue / (1 << this->fractionalBits);
}

// this converts the fixed point value to an int by shifting the bits to the right
int Fixed::toInt()const{
    return this->fixedPointValue >> this->fractionalBits;
}

Fixed & Fixed::operator = (const Fixed & rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(rhs.getRawBits());
    return *this;
}

/* this overloads the std::ostream operator, providing a way to call std::cout directly
on a Fixed object */
std::ostream & operator << (std::ostream &o, Fixed const & object){
    o << object.toFloat();
    return o;
}