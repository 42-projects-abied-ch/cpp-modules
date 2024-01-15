#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/macros.h"
#include <iostream>

int main(){
	std::cout << RED << "\n--- Constructors ---\n" << RESET << std::endl;	
	ClapTrap _Marco("Marco");
	ScavTrap _Arthur("Arthur");
	std::cout << RED << "\n--- Moves ---\n" << RESET << std::endl;
	_Marco.attack("Arthur");
	_Arthur.takeDamage(0);
	_Arthur.beRepaired(20);
	_Arthur.attack("Marco");
	_Marco.takeDamage(_Arthur.getAttackDamage());

	std::cout << RED << "\n--- Destructors ---\n" << RESET << std::endl;
	return 0;
}