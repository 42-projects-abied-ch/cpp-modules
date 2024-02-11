#include "../inc/RobotomyRequestForm.hpp"
#include <exception>

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(72, 45, "Robotomy Request Form")
{
    this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void    RobotomyRequestForm::pureVirtual()
{

}

const char  *RobotomyRequestForm::RobotomyFailure::what() const throw()
{
    return "Robotomy Failed - Patient Is More Stupid Now";
}

void    RobotomyRequestForm::doRobotomy() const
{
    srand(static_cast<unsigned int>(time(NULL)));
    bool    robotomySuccess = rand() % 2;

    try
    {
        std::cout << "Brzr*rzr**rzrzr*zzz*** (Drilling Noises)" << std::endl;
        if (robotomySuccess == false)
            throw RobotomyFailure();
        else
            std::cout << this->_target << "'s Robotomy Successful!!" << std::endl;
    }
    catch (const std::exception &successCheck)
    {
        std::cerr << successCheck.what() << std::endl;
    }
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
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
            doRobotomy();
        }
    }
    catch (const std::exception &requirementCheck)
    {
        std::cerr << "Cannot Perform Robotomy: " << requirementCheck.what() << std::endl;
    }
}