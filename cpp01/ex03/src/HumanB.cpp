#include "../inc/HumanB.hpp"


HumanB::HumanB(std::string name) : name(name){
	std::cout << this->name << " spawned" << std::endl;
	this->_Weapon = NULL;
}

HumanB::~HumanB(){
	std::cout << this->name << " died" << std::endl;
}

void HumanB::attack() const{
	if (this->_Weapon)
		std::cout << this->name << " attacks with their " << (*(this->_Weapon)).getType() << std::endl;
	else 
		std::cout << this->name << " tries to attack but fails miserably" << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon){
	this->_Weapon = &newWeapon;
}