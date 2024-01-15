#pragma once

#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

class ScavTrap : public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &other);
		void attack(const std::string &target);
		void guardGate();
};

std::ostream &operator << (std::ostream &out, const ScavTrap &scavTrap);