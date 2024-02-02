#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <sstream>

class Zombie{
	public:
		Zombie();
		~Zombie();
		void announce();
		void setName(std::string name);
	private:
		std::string name;
};

void 	randomChump(std::string name);
Zombie	*zombieHorde(int n, std::string name);

#endif