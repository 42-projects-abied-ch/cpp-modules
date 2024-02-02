#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl{
    typedef void (Harl::*MemberFunction)(void);
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
    private:
        void debug();
        void info();
        void warning();
        void error();
};

#endif