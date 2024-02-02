#pragma once

#include <iostream>
#include <ostream>

class ClapTrap{
	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string);
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap();

		virtual ClapTrap &operator = (const ClapTrap &other);

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		virtual void attack(const std::string &target);
		virtual std::string getName() const;
		virtual unsigned int getHitPoints() const;
		virtual unsigned int getEnergyPoints() const;
		virtual unsigned int getAttackDamage() const;
};

std::ostream &operator << (std::ostream &out, const ClapTrap &clapTrap);