#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
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
			throw Bureaucrat::GradeTooHighException();
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
			throw Bureaucrat::GradeTooLowException();
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
	return "Grade Too low";
}

void	Bureaucrat::signForm(Form &_Form)
{
	_Form.beSigned(*this);
	try
	{
		if (_Form.isSigned() == false)
			throw Bureaucrat::GradeTooLowException();
		else
			std::cout << this->_name << " Signed " << _Form.getName() << std::endl;
	}
	catch (const std::exception _gradeCheck)
	{
		std::cerr << this->_name << " Could Not Sign " << _Form.getName();
		std::cerr << " Because " << _gradeCheck.what() << std::endl;
	}
}

std::ostream	&operator << (std::ostream &out, const Bureaucrat &_Bureaucrat)
{
	std::cout << "Bureaucrat " << _Bureaucrat.getName() << "'s grade is [" << _Bureaucrat.getGrade() << "]" << std::endl;
	return out;
}