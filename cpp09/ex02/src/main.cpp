#include "../inc/PmergeMe.hpp"
#include <cstddef>
#include <vector>

int main(int argc, char **argv)
{
	try
	{
		verifyInput(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	PmergeMe _mergeMeBaby;
}