#include "../inc/Brain.hpp"
#include <sstream>

Brain::Brain(){
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++){
		std::ostringstream oss;
		oss << "Idea #" << i + 1;
        this->ideas[i] = oss.str();
	}
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other){
	std::string *otherIdeas = other.ideas;
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        this->ideas[i] = otherIdeas[i] + " (copy)";
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(){
    delete [] this->ideas;
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other){
    for (int i = 0; i < 100; i++){
        this->ideas[i] = other.ideas[i] + " (assignation)";
    }
    std::cout << "Brain assignation operator called" << std::endl;
    return *this;
}

std::string *Brain::getIdeas(){
    return (this->ideas);
}