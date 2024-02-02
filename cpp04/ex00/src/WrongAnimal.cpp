#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
    std::cout << "Wrong animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type){
    std::cout << "Wrong animal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Wrong animal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
    std::cout << "Wrong animal assignation operator called" << std::endl;
    this->type = other.type;
    return (*this);
}

std::string WrongAnimal::getType() const{
    return (this->type);
}

void WrongAnimal::makeSound() const{
    std::cout << "What in the love of god is this monstrosity" << std::endl;
}