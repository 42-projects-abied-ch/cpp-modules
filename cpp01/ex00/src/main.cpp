#include "../inc/Zombie.hpp"
#include <cstdlib>

int main(){
	Zombie *marco = newZombie("marco");
	marco->announce();
	randomChump("arthur");
	delete(marco);
	return EXIT_SUCCESS;
}