#include "../inc/Intern.hpp"
#include <cctype>
#include <cstddef>
#include <functional>

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
    this->setFormName(other._formName);
}

Intern  &Intern::operator = (const Intern &other)
{
    if (this == &other)
        return *this;
    this->setFormName(other._formName);
    return *this;
}

Intern::~Intern()
{

}

AForm   *Intern::SCF(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm     *Intern::RRF(const std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm  *Intern::PPF(const std::string target)
{
    return new PresidentialPardonForm(target);
}

void    Intern::setFormName(const std::string name)
{
    this->_formName = name;
    for (size_t i = 0; i < this->_formName.length(); i++)
        this->_formName[i] = std::tolower(static_cast<char>(this->_formName[i]));
}

AForm   *Intern::makeForm(const std::string name, const std::string target)
{
    std::string     keys[] = { "shrubbery creation", "robotomy request", "presidential pardon"};
    AForm           *(Intern::*creators[])(const std::string) = { &Intern::SCF, &Intern::RRF, &Intern::PPF };

    setFormName(name);
    for (size_t i = 0; i < 3; i++)
    {
        if (this->_formName == keys[i])
            return (this->*(creators[i]))(target);
    }
    std::cerr << "Could Not Find Form: [" << name << "]: Name Not Recognized" << std::endl;
    return NULL;
}