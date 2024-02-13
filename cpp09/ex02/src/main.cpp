#include "../inc/PmergeMe.hpp"

std::string	errorMessage(const std::string &message)
{
	return "error: " + message;
}

void	PmergeMe::verifyInput(int argc, char **argv)
{
	if (argc < 2)
		throw PmergeMe::Exception(errorMessage("not enough arguments"));
	for (int i = 1; i < argc; i++)
	{
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
			throw PmergeMe::Exception(errorMessage("invalid element"));
		v_mergeMe.push_back(std::atoi(argv[i]));
	}
}

int main(int argc, char **argv)
{
	try
  	{
		PmergeMe mergeMeBaby(argc, argv);
		mergeMeBaby.v_sort();
  	}
  	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
  	}
}