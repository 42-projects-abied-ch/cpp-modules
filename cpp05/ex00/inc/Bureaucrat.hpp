#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# pragma once

# include <exception>
# include <iostream>

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