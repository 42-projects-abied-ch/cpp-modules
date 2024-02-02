#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    public:
		//default constructor
        Fixed();
		//destructor
        ~Fixed();
		//copy constructor: creates a new object as a copy of an existing object
        Fixed(Fixed const &src);
		//assignation operator: called when '=' is used between two objects
        Fixed & operator=(Fixed const &rhs);
		//int constructor: converts an int to a fixed point value
        Fixed(int const n);
		//float constructor: converts a float to a fixed point value
        Fixed(float const n);
        int getRawBits(void)const;
        void setRawBits(int const raw);
		//returns the fixed point value as a float
        float toFloat(void)const;
		//returns the fixed point value as an int
        int toInt(void)const;
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
};

//overload() the << operator to print the fixed point value
std::ostream & operator << (std::ostream &o, Fixed const &rhs);

#endif