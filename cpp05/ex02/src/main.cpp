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
	delete PPF;
	delete unsignedPPF;
}

int main()
{
	PPFTest();
}