#ifndef INTERN_HPP
# define INTERN_HPP

#include <exception>
# pragma once

# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

		std::string    _formName;

	public:

		Intern();
		~Intern();

		AForm		*makeForm(const std::string name, const std::string target);

		AForm		*PPF(const std::string target);
		AForm		*RRF(const std::string target);
		AForm		*SCF(const std::string target);

		void		setFormName(const std::string name);               
};

#endif