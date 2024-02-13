#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	verifyInput(argc, argv);
	setJacobsthal();
	std::cout << "PmergeMeconstructor called" << std::endl;
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

void PmergeMe::v_mergeInsert(int numOfElement, int elemSizeOfElement)
{
	if (numOfElement == 1)
		return;
	vector v_top;
	vector v_bottom;
	v_sortPairs(numOfElement, elemSizeOfElement);
	v_mergeInsert(numOfElement / 2, elemSizeOfElement * 2);
	v_insert(numOfElement, elemSizeOfElement, v_top, v_bottom);
}

void PmergeMe::printResult()
{
	std::cout << "sort time for std::vector: " << v_sortTime << "μs" << std::endl;
	std::cout << "sort time for std::deque: " << d_sortTime_ << "μs" << std::endl;
}

