#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap();
		FragTrap &operator=(const FragTrap &other);
		void attack(const std::string &target);
		void highFiveGuys();
};

std::ostream &operator << (std::ostream &out, const FragTrap &fragTrap);