#include <iostream>
#include "../inc/Fixed.hpp"

int main(){
    Fixed a;
    Fixed const b( 10 ); Fixed const c( 42.42f ); Fixed const d( b );
    a = Fixed( 1234.4321f );
	/* a == 1234.43 because 1234.4321 is approximated to the nearest value 
	that can be represented with 1/256 (8bits)*/
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
	/* c == 42.4219 because the fractional part of the number is converted 
	to a fixed point value with a precision of 8 bits (1/256)  */
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}