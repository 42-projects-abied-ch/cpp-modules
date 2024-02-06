#ifndef RPN_HPP
# define RPN_HPP

# pragma once

# include <stack>
# include <iostream>

class InvalidExpression : public std::exception
{
    virtual const char *what() const throw();
};

class InvalidCharacter : public std::exception
{
    virtual const char *what() const throw();
};

void    RPN(std::string tokens);
bool    isOperator(char c);

#endif