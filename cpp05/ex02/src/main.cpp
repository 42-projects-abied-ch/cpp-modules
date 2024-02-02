#include "../inc/Bureaucrat.hpp"
#include "../inc/ColorCodes.h"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>

void	PPFTest()
{
	PresidentialPardonForm *PPF = new PresidentialPardonForm("Bender");
	PresidentialPardonForm *unsignedPPF = new PresidentialPardonForm("Your Mum");
	Bureaucrat Arthur("Arthur", 25);

	std::cout << Arthur << std::endl;
	Arthur.signForm(*PPF);
	std::cout << std::endl;
	Arthur.decrementGrade();
	std::cout << Arthur << std::endl;
	std::cout << std::endl;
	Arthur.signForm(*PPF);
	std::cout << *PPF << std::endl;
	PPF->execute(Arthur);
	for (int i = 25; i > 0; i--)
		Arthur.incrementGrade();
	std::cout <<std::endl << Arthur << std::endl;
	PPF->execute(Arthur);
	std::cout << std::endl;
	unsignedPPF->execute(Arthur);
	std::cout << std::endl;
	delete PPF;
	delete unsignedPPF;
}

void	SCFTest()
{
	ShrubberyCreationForm *SCF = new ShrubberyCreationForm("\?\?\?\?");
	ShrubberyCreationForm *unsignedSCF = new ShrubberyCreationForm("Your Mum");
	Bureaucrat Arthur("Arthur", 148);

	std::cout << Arthur << std::endl;
	unsignedSCF->execute(Arthur);
	while (Arthur.getGrade() > SCF->executionRequirement())
		Arthur.incrementGrade();
	std::cout << "\n" << Arthur << std::endl;
	Arthur.signForm(*SCF);
	std::cout << std::endl;
	SCF->execute(Arthur);
	std::cout << std::endl;
	unsignedSCF->execute(Arthur);
	delete SCF;
	delete unsignedSCF;
}

int main()
{
	std::cout << BOLDRED << "PRESIDENTIAL PARDON FORM\n" << std::endl;
	PPFTest();
	std::cout << BOLDRED << "SHRUBBERY CREATION FORM\n" << std::endl;
	SCFTest();
	std::cout << BOLDRED << "ROBOTOMY REQUEST FORM\n" << std::endl;
}