#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include "../inc/ColorCodes.h"
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

void	trySign(Bureaucrat &_Bureaucrat, Form &_Form)
{
	std::cout << std::endl;
	std::cout << BOLDRED << _Bureaucrat.getName() << " Tries To Sign " << _Form.getName() << RESET << std::endl;
	std::cout << std::endl;
	std::cout << BOLDGREEN;
	std::cout << _Bureaucrat;
	std::cout << RESET;
	std::cout << std::endl;
	std::cout << _Form;
	std::cout << std::endl;
	_Form.beSigned(_Bureaucrat);
	_Bureaucrat.signForm(_Form);
	std::cout << std::endl;
	std::cout << _Form;
}

int main()
{
	Form		sickLeave(130, 80, "Sick Leave Request");
	Form		Vacation(10, 5, "Vacation Request");
	
	Bureaucrat	Filip("Filip", 150);
	Bureaucrat	Felix("Felix", 1);

	trySign(Filip, sickLeave);
	trySign(Filip, Vacation);
	trySign(Felix, sickLeave);
	trySign(Felix, Vacation);
}