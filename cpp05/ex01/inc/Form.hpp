#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <string>
# pragma once

# include <iostream>
# include "Bureaucrat.hpp"
class Form
{
	private:

		bool 				_signed;
		const int			_requiredForSignature;
		const int			_requiredForExecution;
		const std::string 	_name;

		Form();

	public:

		Form(const int requiredForSignature, const int requiredForExecution, const std::string name);
		Form(const Form &other);
		Form	&operator = (const Form &other);
		~Form();

		bool				isSigned() const;
		int					signatureRequirement() const;
		int					executionRequirement() const;
		const std::string	getName() const;

		void				beSigned(const Bureaucrat _Bureaucrat);

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

std::ostream	&operator << (std::ostream &out, const Form &_Form);

#endif