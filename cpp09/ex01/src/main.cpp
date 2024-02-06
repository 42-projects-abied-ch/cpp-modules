#include "../inc/RPN.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    try
    {
        RPN(argv[1]);
    }
    catch (std::exception &InvalidExpression)
    {
        std::cout << "Error" << std::endl;
        return EXIT_FAILURE;
    }
}