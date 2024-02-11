#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{
    public:
		HumanB(std::string name);
		~HumanB();
        void attack() const;
		void setWeapon(Weapon &newWeapon);
    private:
		Weapon	*_Weapon;
		std::string name;
};

#endif