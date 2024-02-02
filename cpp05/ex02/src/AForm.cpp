#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ColorCodes.h"
#include <exception>
#include <iostream>
#include <string>

AForm::AForm() : _signed(false), _requiredForSignature(150), _requiredForExecution(150), _name("Default")
{

}

AForm::AForm(const int sign, const int exec, const std::string name) : _signed(false), _requiredForSignature(sign), _requiredForExecution(exec), _name(name)
{

}

AForm::~AForm()
{

}

int	AForm::signatureRequirement() const
{
	return this->_requiredForSignature;
}

int	AForm::executionRequirement() const
{
	return this->_requiredForExecution;
}

const std::string	AForm::getName() const
{
	return this->_name;
}

bool	AForm::isSigned() const
{
	return this->_signed;
}

void	AForm::beSigned(const Bureaucrat _Bureaucrat)
{
	try
	{
		if (_Bureaucrat.getGrade() > this->_requiredForSignature)
			throw GradeTooLowException();
		else
			this->_signed = true;
	}
	catch (const std::exception &_gradeCheck)
	{

	}
}

void	AForm::execute(const Bureaucrat &executor)
{
	(void)executor;
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return "Form Not Signed";
}

std::ostream	&operator << (std::ostream &out, const AForm &_Form)
{
	std::cout << BOLDRED << "\n---------FORM-INFO--------" << RESET << std::endl;
	std::cout << "Name:\t\t\t\t[" << _Form.getName() << "]" << std::endl;
	std::cout << "Required Grade For Signature:\t[" << _Form.signatureRequirement() << "]" << std::endl;
	std::cout << "Required Grade For Execution:\t[" << _Form.executionRequirement() << "]" << std::endl;
	std::cout << "Form Status:\t\t\t" << (_Form.isSigned() ? "[Signed]" : "[Unsigned]") << std::endl;
	return out;
}