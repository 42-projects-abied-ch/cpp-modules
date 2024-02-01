#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

Form::Form() : _signed(false), _requiredForSignature(150), _requiredForExecution(150), _name("Default")
{

}

Form::Form(const int sign, const int exec, const std::string name) : _signed(false), _requiredForSignature(sign), _requiredForExecution(exec), _name(name)
{

}

Form::Form(const Form &other) : _signed(other._signed), _requiredForSignature(other._requiredForSignature), _requiredForExecution(other._requiredForExecution), _name(other._name)
{

}

Form::~Form()
{

}

int	Form::signatureRequirement() const
{
	return this->_requiredForSignature;
}

int	Form::executionRequirement() const
{
	return this->_requiredForExecution;
}

const std::string	Form::getName() const
{
	return this->_name;
}

bool	Form::isSigned() const
{
	return this->_signed;
}

void	Form::beSigned(const Bureaucrat _Bureaucrat)
{
	try
	{
		if (_Bureaucrat.getGrade() > this->_requiredForSignature)
			throw Form::GradeTooLowException();
		else
			this->_signed = true;

	}
	catch (const std::exception &_gradeCheck)
	{
		std::cerr << _gradeCheck.what() << std::endl;
	}
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

std::ostream	&operator << (std::ostream &out, const Form &_Form)
{
	std::cout << "Name: " << _Form.getName() << std::endl;
	std::cout << "Required Grade For Signature: " << _Form.signatureRequirement() << std::endl;
	std::cout << "Required Grade For Execution: " << _Form.executionRequirement() << std::endl;
	std::cout << "Form Status: " << (_Form.isSigned() ? "Signed" : "Unsigned") << std::endl;
	return out;
}