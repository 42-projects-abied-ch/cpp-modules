#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal{
    protected:
        std::string	type;
    public:
        WrongCat();
        WrongCat(const WrongCat &other);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &other);
        
        void makeSound() const;
};

#endif