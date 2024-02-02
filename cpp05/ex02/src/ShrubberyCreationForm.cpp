#include "../inc/ShrubberyCreationForm.hpp"
#include <exception>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(145, 137, "Shrubbery Creation Form")
{
    this -> _target = target; 
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

void    ASCIITREE()
{
    
}

void    ShrubberyCreationForm::execute(const Bureaucrat &executor)
{
    try
    {
        if (executor.getGrade() > this->executionRequirement())
            throw GradeTooLowException();
        else if (this->isSigned() == false)
            throw FormNotSignedException()
        else

    }
    catch (const std::exception &requirementCheck)
    {

    }
}