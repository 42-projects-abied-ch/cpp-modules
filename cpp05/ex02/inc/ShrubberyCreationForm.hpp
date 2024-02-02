#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
# pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : virtual public AForm
{
    private:

        ShrubberyCreationForm();

        std::string   _target;

    public:

        ShrubberyCreationForm(const std::string target);
        ~ShrubberyCreationForm();

        void    execute(const Bureaucrat &executor) const;

        void    pureVirtual();

        void                    doShrubbery() const;
        const std::string       ASCIITREE(const std::string ID) const;
};

#endif