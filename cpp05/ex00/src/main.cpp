#include "../inc/Bureaucrat.hpp"
#include <iostream>

void	tryIncrement(Bureaucrat &_Bureaucrat)
{
	for (int i = 0; i < 150; i++)
	{
		if (i % 10 == 0)
			std::cout << _Bureaucrat;
		if (_Bureaucrat.getGrade() == 1)
		{
			_Bureaucrat.incrementGrade();
			std::cout << std::endl;
			return ;
		}
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
		if (_Bureaucrat.getGrade() == 150)
		{
			_Bureaucrat.decrementGrade();
			std::cout <<std::endl;
			return ;
		}
		_Bureaucrat.decrementGrade();
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "----wrong-inputs----\n" << std::endl;
	Bureaucrat GradeTooLow("--", -1);
	Bureaucrat GradeTooHigh("--", 151);
	std::cout << "----exception-handlling----\n" << std::endl;
	Bureaucrat Filip("Filip", 150);
	Bureaucrat Felix("Felix", 1);

	tryDecrement(Filip);
	tryIncrement(Felix);
}