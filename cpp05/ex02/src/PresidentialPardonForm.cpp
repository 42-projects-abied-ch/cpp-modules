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

void    PresidentialPardonForm::execute(const Bureaucrat &executor)
{
    try
    {
        if (executor.getGrade() > this->executionRequirement())
            throw GradeTooLowException();
        else if (this->isSigned() == false)
            throw FormNotSignedException();
        else
            std::cout << this->_target << " has been pardoned by Zaphox Beeblebrox." << std::endl;
    }
    catch (const std::exception &requirementCheck)
    {
        std::cerr << executor.getName() << " Could Not Execute Form: [";
        std::cerr << this->getName() << "]: " << requirementCheck.what() << std::endl;
    }
}