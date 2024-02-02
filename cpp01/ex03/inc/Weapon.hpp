#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon{
	public:
		Weapon(std::string type);
		~Weapon();
		std::string getType() const;
		void setType(std::string newType);
	private:
		std::string	type;
};

#endif