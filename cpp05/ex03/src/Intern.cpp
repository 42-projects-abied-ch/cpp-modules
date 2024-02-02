#include "../inc/Intern.hpp"
#include <cctype>

Intern::Intern()
{

}

Intern::~Intern()
{

}

ShrubberyCreationForm   *Intern::SCF(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

RobotomyRequestForm     *Intern::RRF(const std::string target)
{
    return new RobotomyRequestForm(target);
}

PresidentialPardonForm  *Intern::PPF(const std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm   *Intern::makeForm(const std::string name, const std::string target)
{
    std::string     str = name;
    std::string   keys[] = { "shrubbery creation form", "robotomy request form", "presidential pardon form"};
    void (*fct[3])(void) = { &Intern::SCF, }

    for (size_t i = 0; i < str.length(); i++)
        str[i] = std::tolower(static_cast<char>(str[i]));

}