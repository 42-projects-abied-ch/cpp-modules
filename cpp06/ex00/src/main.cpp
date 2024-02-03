#include "../inc/ScalarConverter.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "./ScalarConverter [Char/Int/Float/Double]" << std::endl;
        return EXIT_FAILURE;
    }
    std::string input = argv[1];
    ScalarConverter _ScalarConverter = ScalarConverter();
    _ScalarConverter.setInput(input);
    _ScalarConverter.printConverted();
}