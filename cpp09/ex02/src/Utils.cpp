#include "../inc/PmergeMe.hpp"

// constructs an error message by prepending a predefined error prefix to the given message
// @param message - the specific message to be formatted
// @return - a concatenated string of the global ERROR prefix and the input
std::string	errorMessage(const std::string &message)
{
	return ERROR + message;
}

// prints the result of a sorting operation
// @param size - number of elements in the dataset
// @param what - description of the dataset used for sorting
// @param time - duration of the sorting process in microseconds
// @param comparisons- total number of comparisons made during the sorting process
void printResult(const int size, const std::string &what, const clock_t &time, int comparisons)
{
	std::cout << "sorted " << what << " of size " << size << " in " <<  time << " μs (microseconds) and " << comparisons << " comparisons" << std::endl;
}

// verifies the command line input for the correct format of arguments
// throws an exception if:
//		- the number of arguments is less than 2
//		- any argument is not a number (thus implicitly excluding negative numbers)
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

// initializes the Jacobsthal sequence up to the 30th element to optimize performance
void PmergeMe::setJacobsthal()
{
	// base cases
	jacobsthal[0] = 1;
	jacobsthal[1] = 3;

	for (int i = 2; i < 30; ++i)
		jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
}

// determines the next insertion point based on current index & updates the Jacobsthal index if needed
// 		-> helps in optimizing the insertion phase of the algorithm
// @param index - the current position in the sorting process
// @return - the next index for insertion
int PmergeMe::getNextIndex(int index)
{
	// base cases
	if (index == 0)
		return 1;
	if (index == 1)
		return 3;

	// update Jacobsthal index and return the next value if the index matches
	if (index - 1 == jacobsthal[j_index])
	{
		j_index++;
		return jacobsthal[j_index + 1];
	}
	return index - 1;// default behavior for non-sequence indices
}
