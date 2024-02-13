#include "../inc/PmergeMe.hpp"
#include <ctime>

PmergeMe::PmergeMe(int argc, char **argv)
{
	verifyInput(argc, argv);
	setJacobsthal();
}

PmergeMe::PmergeMe(const PmergeMe &)
{

}

const PmergeMe &PmergeMe::operator=(const PmergeMe &)
{ 
	return *this; 
}

PmergeMe::~PmergeMe()
{

}

PmergeMe::Exception::Exception(const std::string &message) : message(message)
{

}

PmergeMe::Exception::~Exception() throw()
{

}

const char	*PmergeMe::Exception::what() const throw()
{
	return message.c_str();
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

void PmergeMe::v_sortPairs(int num, int elemSize)
{
	v_it it = v_mergeMe.begin();

	for (int i = 0; i < num - 1; i += 2)
	{
		v_it first = it + i * elemSize;
		v_it second = it + (i + 1) * elemSize;

		if (*first < *second)
			std::swap_ranges(first, second, second);
	}
}

void PmergeMe::v_binarySearch(vector &v_top, vector &v_bottom, size_t index, size_t elemSize)
{
	int left = 0, right = index + insertCount;
	v_it bottom_it = v_bottom.begin() + index * elemSize, top_it = v_top.begin();

	if (index == 0)
	{
		v_top.insert(top_it, bottom_it, bottom_it + elemSize);
		return;
	}
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (v_top[mid * elemSize] < *bottom_it)
			left = mid + 1;
		else
			right = mid - 1;
	}
	v_top.insert(top_it + left * elemSize, bottom_it, bottom_it + elemSize);
	insertCount++;
}

void PmergeMe::v_makePairs(int elemCount, int elemSize, vector &v_top, vector &v_bottom)
{
	v_it it = v_mergeMe.begin();

	for (int i = 0; i < elemCount; ++i)
	{
		if (i == elemCount - 1 || i % 2 == 1)
			v_bottom.insert(v_bottom.end(), it + i * elemSize, it + (i + 1) * elemSize);
		else if (i % 2 == 0)
			v_top.insert(v_top.end(), it + i * elemSize, it + (i + 1) * elemSize);
	}
}

void PmergeMe::v_insert(int elemCount, int elemSize, vector &v_top, vector &v_bottom)
{
	int index = 0;
	int v_bottomCount = elemCount / 2 + elemCount % 2;
	j_index = 0;
	insertCount = 0;

	v_makePairs(elemCount, elemSize, v_top, v_bottom);
	for (int i = 0; i < v_bottomCount; ++i)
	{
		index = getNextIndex(index);
		if (index >= v_bottomCount) index = v_bottomCount;
		v_binarySearch(v_top, v_bottom, index - 1, elemSize);
	}
	for (size_t i = 0; i < v_top.size(); ++i)
		v_mergeMe[i] = v_top[i];
}

void PmergeMe::v_mergeInsert(int elemCount, int elemSize)
{
	if (elemCount == 1)
		return;
	vector v_top;
	vector v_bottom;
	v_sortPairs(elemCount, elemSize);
	v_mergeInsert(elemCount / 2, elemSize * 2);
	v_insert(elemCount, elemSize, v_top, v_bottom);
}

void	PmergeMe::v_init(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		v_mergeMe.push_back(std::atoi(argv[i]));
	if (isSorted(v_mergeMe) == true)
		throw Exception(errorMessage("input already sorted"));
}

void	PmergeMe::v_sort(int argc, char **argv)
{
	clock_t start = clock();
	v_init(argc, argv);
	printContainer(v_mergeMe, "std::vector", "before");
	v_mergeInsert(v_mergeMe.size(), 1);
	printContainer(v_mergeMe, "std::vector", "after");
	if (isSorted(v_mergeMe) == false)
		throw Exception(errorMessage("input not sorted correctly, guess i will retry in 3 days"));
	printResult(argc - 1, "std::vector", clock() - start);
}

std::string	errorMessage(const std::string &message)
{
	return "error: " + message;
}

void printResult(const int count, const std::string &what, const clock_t &time)
{
	std::cout << "time to sort " << count << " in container type " << what << ": " << time << "μs" << std::endl;
}

void	PmergeMe::verifyInput(int argc, char **argv)
{
	if (argc < 2)
		throw PmergeMe::Exception(errorMessage("not enough arguments"));
	for (int i = 1; i < argc; i++)
	{
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
			throw PmergeMe::Exception(errorMessage("invalid element"));
	}
}