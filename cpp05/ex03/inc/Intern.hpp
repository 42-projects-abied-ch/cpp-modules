#ifndef INTERN_HPP
# define INTERN_HPP

# pragma once

# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    public:

        Intern();
        ~Intern();

        AForm   *makeForm(const std::string name, const std::string target);

        PresidentialPardonForm  *PPF(const std::string target);
        RobotomyRequestForm     *RRF(const std::string target);
        ShrubberyCreationForm   *SCF(const std::string target);
};

#endif