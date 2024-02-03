#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
# pragma once

# include <exception>
# include <iostream>


class AForm;

class Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;
		Bureaucrat();

	public:

		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat	&operator = (const Bureaucrat &other);
		~Bureaucrat();

		int					getGrade() const;
		const std::string&	getName() const;

		void				incrementGrade();
		void				decrementGrade();

		void				signForm(AForm &_Form);
		void				executeForm(const AForm &_Form) const;

		class GradeTooHighException : public std::exception
		{
			virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

std::ostream	&operator << (std::ostream& out, const Bureaucrat &_Bureaucrat);

#endif