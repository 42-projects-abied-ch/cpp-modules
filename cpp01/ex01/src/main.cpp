#include "../inc/Zombie.hpp"
#include <cstdlib>

int main(int argc, char **argv){
	if (argc != 3)
	{
		std::cout << "./moarbrainz zombieName zombieCount";
		return (EXIT_FAILURE);
	}
	int	zombieCount = std::atoi(argv[2]);
	Zombie* horde = zombieHorde(zombieCount, argv[1]);
	for (int i = 0; i < zombieCount; i++)
		horde[i].announce();
	delete[] horde;
	return EXIT_SUCCESS;
}