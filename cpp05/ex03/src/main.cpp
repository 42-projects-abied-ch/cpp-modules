#include "../inc/Bureaucrat.hpp"
#include "../inc/ColorCodes.h"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"
#include <cstdlib>
#include <iostream>
#include <string>


int main(int argc, char **argv)
{
    if (argc != 5)
    {
        std::cerr << "Execution: ./Intern \"Bureaucrat Name\" \"Bureaucrat Grade\" \"Form Name\" \"Target\"" << std::endl;
        return EXIT_FAILURE;
    }
    AForm*      form;
    Intern      someRandomIntern;
    Bureaucrat  Arthur(argv[1], std::stoi(argv[2]));
    form = someRandomIntern.makeForm(argv[3], argv[4]);
    if (form == NULL)
        return EXIT_FAILURE;
    Arthur.signForm(*form);
    Arthur.executeForm(*form);
    delete form;
}