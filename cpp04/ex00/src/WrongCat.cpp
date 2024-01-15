#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : type("WrongCat"){
    std::cout << "Wrong cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other){
    this->type = other.getType();
    std::cout << "Wrong cat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "Wrong cat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
    std::cout << "Wrong cat assignation operator called" << std::endl;
    this->type = other.type;
    return (*this);
}

void WrongCat::makeSound() const{
    std::cout << "Moo moo" << std::endl;
}