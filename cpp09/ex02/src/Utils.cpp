#include "../inc/PmergeMe.hpp"

std::string	errorMessage(const std::string &message)
{
	return ERROR + message;
}

void printResult(const int size, const std::string &what, const clock_t &time, int comparisons)
{
	std::cout << "sorted " << what << " of size " << size << " in " <<  time << " μs (microseconds) and " << comparisons << " comparisons" << std::endl;
}

void	PmergeMe::verifyInput(int argc, char **argv)
{
	if (argc < 2)
		throw PmergeMe::Exception(errorMessage(ERR_ARGC));
	for (int i = 1; i < argc; i++)
	{
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
			throw PmergeMe::Exception(errorMessage(ERR_INVALID));
	}
}

void PmergeMe::setJacobsthal()
{
	jacobsthal[0] = 1;
	jacobsthal[1] = 3;

	for (int i = 2; i < 30; ++i)
		jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
}


int PmergeMe::getNextIndex(int index)
{
	if (index == 0)
		return 1;
	if (index == 1)
		return 3;
	if (index - 1 == jacobsthal[j_index])
	{
		j_index++;
		return jacobsthal[j_index + 1];
	}
	return index - 1;
}
