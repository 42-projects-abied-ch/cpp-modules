#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap " << this->name << " spawned!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other){
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << this->name << " died :/" << std::endl;
}

void ScavTrap::attack(const std::string &target){
	if (this->energyPoints == 0){
		std::cout << this->name << " has no energy points left!" << std::endl;
		return ;	
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
	std::cout << *this;	
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->name << " has entered Gate keeper mode!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ScavTrap &scavTrap){
	out << "ScavTrap " << scavTrap.getName() << " has " << scavTrap.getHitPoints() << " hit points and " << scavTrap.getEnergyPoints() << " energy points!" << std::endl;
	return out;
}

