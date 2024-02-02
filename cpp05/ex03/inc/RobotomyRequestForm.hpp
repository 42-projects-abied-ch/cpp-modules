#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <exception>
# pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : virtual public AForm
{
    private:

        RobotomyRequestForm();

        std::string		_target;

    public:

        RobotomyRequestForm(const std::string target);
        ~RobotomyRequestForm();

        void    execute(const Bureaucrat &executor) const;
		void	doRobotomy() const;

        void    pureVirtual();

		class RobotomyFailure : public std::exception
		{
			virtual const char	*what() const throw();
		};

};

#endif