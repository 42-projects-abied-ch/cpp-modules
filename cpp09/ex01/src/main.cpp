#include "../inc/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    std::cout << RPN(argv[1]) << std::endl;
}