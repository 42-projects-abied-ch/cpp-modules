#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : virtual public AForm
{
    private:

        std::string   _target;

    public:

        ShrubberyCreationForm(const std::string target);
        ~ShrubberyCreationForm();

        void    execute(const Bureaucrat &executor);

        void                    doShrubbery();
        const std::string       ASCIITREE(const std::string ID);
};

#endif