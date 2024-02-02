#include "../inc/Zombie.hpp"

std::string	getName(std::string name, int index){
    std::ostringstream oss;
    oss << name << (index + 1);
    return oss.str();
}

void	Zombie::setName(std::string name){
	this->name = name;
}

Zombie	*zombieHorde(int n, std::string name){
	Zombie	*horde = new Zombie[n];
	for (int i = 0; i < n; i++){
		horde[i].setName(getName(name, i));
	}
	return (&(horde[0]));
}

