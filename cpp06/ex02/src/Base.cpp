#include "../inc/Base.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base()
{

}
Base	*generate()
{
    srand(static_cast<unsigned int>(time(NULL)));
    bool    ABC = rand() % 3;

}