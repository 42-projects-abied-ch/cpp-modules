#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/AForm.hpp"
#include <exception>

PresidentialPardonForm::PresidentialPardonForm(const std::string _target) : AForm(25, 5, "Presidential Pardon Form")
{
    this->_target = _target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void    PresidentialPardonForm::pureVirtual()
{

}

void    PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    try
    {
        if (executor.getGrade() > this->executionRequirement())
            throw GradeTooLowException();
        else if (this->isSigned() == false)
            throw FormNotSignedException();
        else
        {
            std::cout << executor.getName() << " Executed Form: [" << this->getName() << "]\n" << std::endl;
            std::cout << this->_target << " has been pardoned by Zaphox Beeblebrox." << std::endl;
        }
    }
    catch (const std::exception &requirementCheck)
    {
        std::cerr << executor.getName() << " Could Not Execute Form: [";
        std::cerr << this->getName() << "]: " << requirementCheck.what() << std::endl;
    }
}