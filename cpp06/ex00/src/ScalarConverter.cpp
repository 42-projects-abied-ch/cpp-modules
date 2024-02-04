#include "../inc/ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <limits>
#include <string>

ScalarConverter::ScalarConverter() : dataType(UNDEFINED), decimal(false)
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	this->input = other.getInput();
	this->dataType = other.getDataType();
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &other)
{
	if (this == &other)
		return *this;
	this->input = other.getInput();
	this->dataType = other.getDataType();
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

std::string ScalarConverter::getInput() const
{
	return this->input;
}

e_dataType    ScalarConverter::getDataType() const
{
	return this->dataType;
}

void    ScalarConverter::setInput(const std::string input)
{
	this->input = input;
	this->dataType = UNDEFINED;
}

bool    ScalarConverter::checkFloat(const size_t i)
{
	if (static_cast<char>(this->input[i]) == 'f' && this->input.length() == i + 1 && std::isdigit(static_cast<char>(this->input[i - 1])) == true)
	{
		this->dataType = FLOAT;
		return true;
	}
	return false;
}

bool    ScalarConverter::checkValidDecimal(const int i)
{
	if (static_cast<char>(this->input[i]) == '.')
	{
		if (this->decimal == false)
			this->decimal = true;
		else
			return false;
	}
	return true;
}

bool    ScalarConverter::checkChar()
{
	if (this->input.length() == 1 && std::isdigit(static_cast<char>(this->input[0])) == false)
	{
		this->dataType = CHAR;
		return true;
	}
	return false;
}

bool    ScalarConverter::checkNaN()
{
	if (this->input == "nan" || this->input == "nanf")
	{
		this->dataType = _NAN;
		return true;
	}
	return false ;
}

bool    ScalarConverter::checkInf()
{
	if (this->input == "+inf" || this->input == "-inf" || this->input == "+inff" || this->input == "-inff")
	{
		this->dataType = INF;
		return true;
	}
	return false ;
}

void    ScalarConverter::setType()
{
	this->dataType = NO_TYPE_FOUND;
	this->decimal = false;

	if (this->checkChar() == true)
		return ;
	else if (this->checkNaN() == true)
		return ;
	else if (this->checkInf() == true)
		return ;
	else
	{
		bool sign = (static_cast<char>(input[0]) == '+' || static_cast<char>(input[0]) == '-');

		for (size_t i = 0 + sign; i < this->input.length(); i++)
		{
			if (this->checkFloat(i) == true)
				return ;
			else if (this->checkValidDecimal(i) == false)
				return ;
			else if (std::isdigit(static_cast<char>(this->input[i])) == false)
				return ;
		}
		if (this->decimal == true)
			this->dataType = DOUBLE;
		else
			this->dataType = INT;
	}
}

void    ScalarConverter::printChar() const
{
	char    ch = static_cast<char>(this->input[0]);

	if (std::isprint(ch) == true)
		std::cout << "Char:\t[" << ch << "]" << std::endl;
	else
		std::cerr << "Char:\t[Is Not Printable]" << std::endl;
	std::cout << "Int:\t[" << static_cast<int>(ch) << "]" << std::endl;
	std::cout << "Float:\t[" << static_cast<float>(ch) << "]" << std::endl;
	std::cout << "Double:\t[" << static_cast<double>(ch) << "]" << std::endl;
}

void    ScalarConverter::printInt() const
{
	long    overflowCheck = std::strtol(this->input.c_str(), NULL, 10);
	int     n = overflowCheck;

	if (overflowCheck > INT_MAX || overflowCheck < INT_MIN)
	{
		std::cerr << "Int Error:\t[Input Overflowed - Going Through With Conversion]" << std::endl;
		return ;
	}
	if (n >= CHAR_MIN && n <= CHAR_MAX)
	{
		if (std::isprint(n) == true)
			std::cout << "Char: [" << static_cast<char>(n) << "]" << std::endl;
		else
			std::cerr << "Char:\t[Not Printable]" << std::endl;
	}
	else
		std::cerr << "Char:\t[Could Not Convert]" << std::endl;
	std::cout << "Int:\t[" << n << "]" << std::endl;
	std::cout << "Float:\t[" << static_cast<float>(n);
	if (n < 1000000)
		std::cout << ".0f]" << std::endl;
	else
		std::cout << "f]" << std::endl;
	std::cout << "Double:\t[" << static_cast<double>(n);
	if (n < 1000000)
		std::cout << ".0]" << std::endl;
	else
		std::cout << std::endl;
}

void    ScalarConverter::printDouble() const
{
	double  d = std::strtod(this->input.c_str(), NULL);
	double  temp;

	if (d >= CHAR_MIN && d <= CHAR_MAX)
	{
		char ch = static_cast<char>(d);
		if (std::isprint(ch) == true)
			std::cout << "Char:\t[" << ch << "]" << std::endl;
		else
			std::cerr << "Char:\t[Not Printable]" << std::endl;
	}
	else
		std::cerr << "Char:\t[Could Not Convert]" << std::endl;
	if (d < INT_MIN || d > INT_MAX)
		std::cerr << "Int:\t[Could Not Convert]" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "Float:\t[" << static_cast<float>(d);
	if (std::modf(d, &temp) == 0 && d < 999999.5)
		std::cout << ".0f]" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "Double:\t[" << d;
	if (std::modf(d, &temp) == 0 && d < 999999.5)
		std::cout << ".0]";
	std::cout << std::endl;
}

void    ScalarConverter::printFloat() const
{
	float   f = strtof(this->input.c_str(), NULL);
	double  temp;

	if (f >= CHAR_MIN && f <= CHAR_MAX)
	{
		char ch = static_cast<char>(f);
		if (std::isprint(ch) == true)
			std::cout << "Char:\t[" << ch << "]" << std::endl;
		else
			std::cerr << "Char:\t[Not Printable]" << std::endl;
	}
	else
		std::cerr << "Char:\t[Could Not Convert]" << std::endl;
	if (f < INT_MIN || f > INT_MAX)
		std::cerr << "Int:\t[Could Not Convert]" << std::endl;
	else
		std::cout << "Int:\t[" << static_cast<int>(f) << std::endl;
	std::cout << "FLoat:\t[" << f;
	if (std::modf(f, &temp) == 0 && f < 999999.5)
		std::cout << ".0f]" << std::endl;
	else
		std::cout << "f]" << std::endl;
	std::cout << "Double:\t[" << static_cast<double>(f);
	if (std::modf(f, &temp) == 0 && f < 999999.5)
		std::cout << ".0]";
	std::cout << std::endl;
}

void    ScalarConverter::printNotANumber() const
{
	double  dtemp;
	float   ftemp;

	std::cout << "Char:\t[Could Not Convert]" << std::endl;    
	std::cout << "Int:\t[Could Not Convert]" << std::endl;
	if (this->input == "nan")
	{
		dtemp = std::numeric_limits<double>::quiet_NaN();
		std::cout << "Float:\t[" << static_cast<float>(dtemp) << "f]" << std::endl;
		std::cout << "Double:\t[" << dtemp << "]" << std::endl;
	}
	else if (this->input == "nanf")
	{
		ftemp = std::numeric_limits<float>::quiet_NaN();
		std::cout << "Float:\t[" << ftemp << "f]" << std::endl;
		std::cout << "Double:\t[" << static_cast<double>(ftemp) << "]" << std::endl;
	}
}

void    ScalarConverter::printInf() const
{
	double  dtemp;
	float   ftemp;

	std::cout << "Char:\t[Could Not Convert]" << std::endl;    
	std::cout << "Int:\t[Could Not Convert]" << std::endl;
	if (this->input.compare(1, 4, "inf") == false)
	{
		dtemp = std::numeric_limits<double>::infinity();
		if (static_cast<char>(this->input[0]) == '-')
			dtemp = -dtemp;
		std::cout << "Float:\t[" << static_cast<float>(dtemp) << "f]" << std::endl;
		std::cout << "Double:\t[" << dtemp << "]" << std::endl;
	}
	else if (this->input.compare(1, 5, "inff") == false)
	{
		ftemp = std::numeric_limits<float>::infinity();
		if (static_cast<char>(this->input[0]) == '-')
			ftemp = -ftemp;
		std::cout << "Float:\t[" << ftemp << "f]" << std::endl;
		std::cout << "Double:\t[" << static_cast<double>(ftemp) << std::endl;
	}
}

void    ScalarConverter::printNonSense() const
{
	std::cout << "I Have No Idea What Type This Is" << std::endl;
}

void    ScalarConverter::printConverted()
{
	void    ( ScalarConverter::*out[] )() const =
	{
	&ScalarConverter::printChar,
	&ScalarConverter::printInt,
	&ScalarConverter::printFloat,
	&ScalarConverter::printDouble,
	&ScalarConverter::printNotANumber,
	&ScalarConverter::printInf,
	&ScalarConverter::printNonSense
	};
	if (this->dataType == UNDEFINED)
		this->setType();
	std::cout << "this->dataType: " << this->dataType << std::endl;
	(this->*(out[this->dataType]))();
}