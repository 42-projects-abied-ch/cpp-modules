#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << this->name << " spawned" << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->name << " died" << std::endl;
}

void	Zombie::announce(){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}