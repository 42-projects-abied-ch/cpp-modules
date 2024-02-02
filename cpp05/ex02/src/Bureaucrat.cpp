#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ColorCodes.h"
#include <exception>
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{

}

Bureaucrat::~Bureaucrat()
{

}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

const std::string	&Bureaucrat::getName() const
{
	return this->_name;
}

void	Bureaucrat::incrementGrade()
{
	try 
	{
		if (this->_grade - 1 < 1)
			throw GradeTooHighException();
		else
			this->_grade--;
	}
	catch (const std::exception &_gradeCheck)
	{
		std::cerr << _gradeCheck.what();
		std::cerr << ": " << *this;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade + 1 > 150)
			throw GradeTooLowException();
		else
			this->_grade++;
	}
	catch (const std::exception &_gradeCheck)
	{
		std::cerr << _gradeCheck.what();
		std::cerr << ": "  << *this;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

void	Bureaucrat::signForm(AForm &_Form)
{
	if (_Form.isSigned() == true)
	{
		std::cout << "[" << _Form.getName() << "] Is Already Signed" << std::endl;
		return ;
	}
	_Form.beSigned(*this);
	try
	{
		if (_Form.isSigned() == false)
			throw GradeTooLowException();
		else
			std::cout << "[" << _Form.getName() << "] Was Signed  By Bureaucrat " << this->_name << std::endl;
	}
	catch (const std::exception &_gradeCheck)
	{
		std::cerr << this->_name << " Could Not Sign Form : [" << _Form.getName();
		std::cerr << "]: " << _gradeCheck.what() << std::endl;
	}
}

std::ostream	&operator << (std::ostream &out, const Bureaucrat &_Bureaucrat)
{
	std::cout << BOLDGREEN << "---------BUREAUCRAT-INFO---------" << RESET << std::endl;
	std::cout << "Name:\t\t\t\t[" << _Bureaucrat.getName() << "]" << RESET << std::endl;
	std::cout << "Grade:\t\t\t\t[" << _Bureaucrat.getGrade() << "]" << RESET << std::endl;
	return out;
}