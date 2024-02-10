#ifndef RPN_HPP
# define RPN_HPP

# pragma once

# include <exception>
# include <stack>
# include <iostream>
# include <climits>
# include <cstdlib>

class InvalidInput : public std::exception
{
	virtual const char	*what() const throw();
};

class InvalidExpression : public std::exception
{
    virtual const char *what() const throw();
};

class InvalidCharacter : public std::exception
{
    virtual const char *what() const throw();
};

class MultipleDigits : public std::exception
{
    virtual const char *what() const throw();
};

class IntegerOverflow : public std::exception
{
	virtual const char	*what() const throw();
};

void    RPN(std::string tokens);
bool    isOperator(char c);

#endif