#include "../inc/Fixed.hpp"

int Fixed::getRawBits() const{
	return this->fixedPointValue;
}

void Fixed::setRawBits(const int raw){
	this->fixedPointValue = raw;
}

Fixed::Fixed(){
	this->fixedPointValue = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src){
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int n){
	// std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = n << this->fractionalBits;
}

Fixed::Fixed(float n){
	// std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(n * (1 << this->fractionalBits));
}

float Fixed::toFloat()const{
	return (float)this->fixedPointValue / (1 << this->fractionalBits);
}

int Fixed::toInt()const{
	return this->fixedPointValue >> this->fractionalBits;
}

Fixed & Fixed::operator = (const Fixed & rhs){
	// std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(rhs.getRawBits());
	return *this;
}

std::ostream & operator << (std::ostream &o, Fixed const & object){
	o << object.toFloat();
	return o;
}

Fixed Fixed::operator + (const Fixed & fixed) const{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator - (const Fixed &fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator * (const Fixed &fixed) const{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator / (const Fixed &fixed) const{
	return Fixed(this->toFloat() / fixed.toFloat());
}

bool Fixed::operator > (const Fixed &fixed) const{
	return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator < (const Fixed &fixed) const{
	return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator <= (const Fixed &fixed) const{
	return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator >= (const Fixed &fixed) const{
	return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator == (const Fixed &fixed) const{
	return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator != (const Fixed &fixed) const{
	return this->toFloat() != fixed.toFloat();
}

// this overloads the preincrement operator to
// increment the fixed point value by 1
Fixed & Fixed::operator ++ (){
	this->fixedPointValue++;
	return *this;
}

// this overloads the predecrement operator to
// decrement the fixed point value by 1
Fixed & Fixed::operator -- (){
	this->fixedPointValue--;
	return *this;
}

// this overloads the operator to
// in/decrement the fixed point value by 1

// the int parameter is a dummy parameter to
// differentiate between the pre and post in/decrement
// it does not have a name because it is not used
// in the function

// the pre in/decrement operator is called first on the current
// object, in/decrementing its fixed point value,

// however, we return the tmp object which is a copy of the
// current object before the incrementation, effectively
// postin/decrementing the current object
Fixed Fixed::operator ++ (int){
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator -- (int){
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed Fixed::min(Fixed &a, Fixed &b){
	return a < b ? a : b;
}

Fixed Fixed::min(Fixed const &a, Fixed const &b){
	return a < b ? a : b;
}

Fixed Fixed::max(Fixed &a, Fixed &b){
	return a > b ? a : b;
}

Fixed Fixed::max(Fixed const &a, Fixed const &b){
	return a > b ? a : b;
}

