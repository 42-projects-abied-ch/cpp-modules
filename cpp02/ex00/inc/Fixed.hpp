#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    public:
		//default constructor
        Fixed();
		//destructor
        ~Fixed();
		//copy constructor: creates a new object as a copy of an existing object
        Fixed(Fixed const & src);
		//assignation operator: called when '=' is used between two objects
        Fixed & operator = (Fixed const&rhs);
		//getter function
        int getRawBits() const;
		//setter function
        void setRawBits(int const raw);
	private:
		//fixed point value
		int	fixedPointValue;
		//number of fractional bits (number of bits used to represent the fractional part of a number)
		static const int nFractBits=8;
};

#endif