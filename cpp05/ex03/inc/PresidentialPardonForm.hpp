#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
#include <string>

#pragma once


class PresidentialPardonForm : virtual public AForm
{
	private:

		PresidentialPardonForm();

		std::string _target;

	public:

		PresidentialPardonForm(const std::string _target);
		~PresidentialPardonForm();

		void    execute(const Bureaucrat &executor) const;

        void    pureVirtual();

};

#endif