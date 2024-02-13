#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv)
{
	try
  	{
		PmergeMe mergeMeBaby(argc, argv);
		mergeMeBaby.v_sort(argc, argv);
  	}
  	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
  	}
}