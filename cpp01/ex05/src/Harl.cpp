#include "../inc/Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void    Harl::debug(){
    std::cout << "i love to have extra bacon on my burger" << std::endl;
}

void    Harl::info(){
    std::cout << "tf why does it cost so much you did not put enough in the first place" << std::endl;
}

void    Harl::warning(){
    std::cout << "give me extra bacon for free, i've been coming here for years and you just started" << std::endl;
}

void    Harl::error(){
    std::cout << "i wanna speak to the manager" << std::endl;
}

void	Harl::complain(std::string arg){
	void	(Harl::*fct[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	msg[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++){
		if (msg[i] == arg)
			(this->*(fct[i]))();
	}
}