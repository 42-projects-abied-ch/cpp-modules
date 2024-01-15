#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    public:
        Fixed();
        Fixed(const Fixed & fixed);
        Fixed(const int intValue);
        Fixed(const float floatValue);
        Fixed & operator=(const Fixed &fixed);
        Fixed operator - (const Fixed &fixed) const;
        Fixed operator + (const Fixed &fixed) const;
		Fixed operator * (const Fixed &fixed) const;
		Fixed operator / (const Fixed &fixed) const;
		Fixed & operator -- ();
        Fixed & operator ++ ();
		Fixed operator -- (int);
		Fixed operator ++ (int);
        ~Fixed();

        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;

		static Fixed min(Fixed &a, Fixed &b);
		static Fixed min(Fixed const &a, Fixed const &b);
		static Fixed max(Fixed &a, Fixed &b);
		static Fixed max(Fixed const &a, Fixed const &b);

		bool operator > (const Fixed &fixed) const;
        bool operator < (const Fixed &fixed) const;
        bool operator >= (const Fixed &fixed) const;
        bool operator <= (const Fixed &fixed) const;
        bool operator == (const Fixed &fixed) const;
        bool operator != (const Fixed &fixed) const;
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & fixed);

#endif