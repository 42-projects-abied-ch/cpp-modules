#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type) : type(type){
}

Weapon::~Weapon(){
}

std::string Weapon::getType() const{
    return this->type;
}

void Weapon::setType(std::string newType){
    this->type = newType;
}