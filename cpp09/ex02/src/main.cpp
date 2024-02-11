#include "../inc/PmergeMe.hpp"

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
	PmergeMe mergeMeBaby;
	mergeMeBaby.v_FordJohnson(argc, argv);
	mergeMeBaby.d_FordJohnson(argc, argv);
}