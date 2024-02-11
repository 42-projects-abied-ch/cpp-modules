#include "../inc/ClapTrap.hpp"
#include "../inc/macros.h"
#include <iostream>

int main(){
	std::cout << RED << "\n--- Constructors ---\n" << RESET << std::endl;	
	ClapTrap _Marco("Marco");
	ClapTrap _Arthur("Arthur");
	std::cout << RED << "\n--- Moves ---\n" << RESET << std::endl;
	_Marco.attack("Arthur");
	_Arthur.takeDamage(0);
	_Arthur.beRepaired(20);
	std::cout << RED << "\n--- Check if able to attack with empty energy ---\n" << RESET << std::endl;
	for(int i = 0; i < 10; i++)
		_Marco.attack("Arthur");
	std::cout << RED << "\n--- Check if able to be repaired with empty energy ---\n" << RESET << std::endl;
	_Marco.beRepaired(20);
	std::cout << RED << "\n--- Check if copy constructor takes up to date object values ---\n" << RESET << std::endl;
	ClapTrap _newMarco(_Marco);
	_newMarco.attack("Arthur");
	_newMarco.beRepaired(20);
	std::cout << RED << "\n--- Check if assignation operator takes up to date object values ---\n" << RESET << std::endl;
	_Arthur = _Marco;
	_Arthur.attack("Marco");
	_Arthur.beRepaired(20);
	std::cout << RED << "\n--- Destructors ---\n" << RESET << std::endl;
	return 0;
}