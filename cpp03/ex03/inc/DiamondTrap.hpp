#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>


class DiamondTrap : virtual public ScavTrap, virtual public FragTrap{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap &other);

		void whoAmI();
		using ScavTrap::attack;
		using FragTrap::hitPoints;
		using ScavTrap::energyPoints;
		using FragTrap::attackDamage;
	private:
		std::string	name;
};

std::ostream	&operator<<( std::ostream &stream, const DiamondTrap &instance );