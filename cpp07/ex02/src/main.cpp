#include "../inc/Array.hpp"
#include <exception>

int main()
{
    Array <std::string> arrA;
    Array <std::string> arrB(3);
    Array <std::string> arrC(5);
    Array <std::string> arrD(arrC);
    
    arrC[0] = "Hello World";

    std::cout << "arrA:\n" << arrA << std::endl;
    std::cout << "arrB:\n" << arrB << std::endl;
    std::cout << "arrC:\n" << arrC << std::endl;

    arrC = arrB;
    arrB[2] = "dlroW olleH";
    try
    {
        arrB[3] = "Jar Jar Binks";
    }
    catch (const std::exception &index)
    {
        std::cerr << index.what() << std::endl;
    }
}