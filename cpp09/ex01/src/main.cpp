#include "../inc/RPN.hpp"

int main(int argc, char **argv)
{
    try
    {
		if (argc != 2)
			throw InvalidInput();
        RPN(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cout << "error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}