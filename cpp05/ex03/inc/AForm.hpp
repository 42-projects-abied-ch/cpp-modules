#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <string>
# pragma once

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
	private:

		bool 				_signed;
		const int			_requiredForSignature;
		const int			_requiredForExecution;
		const std::string 	_name;

	public:

		AForm();
		AForm(const int requiredForSignature, const int requiredForExecution, const std::string name);
		AForm(const AForm &other);
		AForm	&operator = (const AForm &other);
		virtual ~AForm();

		bool						isSigned() const;
		virtual int					signatureRequirement() const;
		virtual int					executionRequirement() const;
		virtual const std::string	getName() const;

		virtual void				pureVirtual() = 0;

		virtual void				execute(const Bureaucrat &executor) const;
		virtual void				beSigned(const Bureaucrat _Bureaucrat);

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char	*what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

std::ostream	&operator << (std::ostream &out, const AForm &_Form);

#endif