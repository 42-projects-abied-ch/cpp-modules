#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

class Harl{
    typedef void (Harl::*MemberFunction)(void);
    public:
        Harl();
        ~Harl();
        void complain(std::string arg);
    private:
        void debug();
        void info();
        void warning();
        void error();
};

#endif