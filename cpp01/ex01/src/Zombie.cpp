#include "../inc/Zombie.hpp"

Zombie::Zombie(){
	std::cout << "new zombie spawned" << std::endl;
}


Zombie::~Zombie(){
	std::cout << this->name << " died" << std::endl;
}

void	Zombie::announce(){
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}