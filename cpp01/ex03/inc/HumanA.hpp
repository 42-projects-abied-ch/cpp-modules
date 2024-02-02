#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "../inc/Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string name, Weapon *_Weapon);
		~HumanA();
		void attack() const;
	private:
		std::string name;
		Weapon *_Weapon;
};

#endif