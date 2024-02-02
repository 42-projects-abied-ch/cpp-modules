#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap " << this->name << " spawned!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other){
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator = (const FragTrap &other){
	std::cout << "FragTrap assignation operator called" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << this->name << " died :/" << std::endl;
}

void FragTrap::highFiveGuys(){
	std::cout << "FragTrap " << this->name << " tries to high five someone but no one likes him" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const FragTrap &fragTrap){
	out << "FragTrap " << fragTrap.getName() << " has " << fragTrap.getHitPoints() << " hit points and " << fragTrap.getEnergyPoints() << " energy points!" << std::endl;
	return out;
}

