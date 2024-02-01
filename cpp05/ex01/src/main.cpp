#include "../inc/Bureaucrat.hpp"
#include <iostream>

void	tryIncrement(Bureaucrat &_Bureaucrat)
{
	std::cout << _Bureaucrat;
	for (int i = 0; i < 150; i++)
	{
		if (i % 10 == 0)
			std::cout << _Bureaucrat;
		_Bureaucrat.incrementGrade();
	}
	std::cout << std::endl;
}

void	tryDecrement(Bureaucrat &_Bureaucrat)
{
	std::cout << _Bureaucrat;
	for (int i = 0; i < 150; i++)
	{
		if (i % 10 == 9)
			std::cout << _Bureaucrat;
		_Bureaucrat.decrementGrade();
	}
	std::cout << std::endl;
}

int main()
{
	Bureaucrat Filip("Filip", 150);
	Bureaucrat Felix("Felix", 1);

	tryDecrement(Felix);
	tryIncrement(Filip);
}