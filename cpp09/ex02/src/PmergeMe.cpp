#include "../inc/PmergeMe.hpp"
#include <cstddef>
#include <deque>
#include <utility>
#include <vector>

PmergeMe::PmergeMe() : v_Comparisons(0)
{

}

PmergeMe::PmergeMe(const PmergeMe &other) : v_MergeMe(other.v_MergeMe), D_mergeMe(other.D_mergeMe)
{

}

PmergeMe::~PmergeMe()
{

}

void	PmergeMe::v_Init(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
		v_MergeMe.push_back(std::atoi(argv[i]));
}

std::vector <std::pair <int, int> >	PmergeMe::v_MakePairs(std::vector <int> v)
{
	std::vector <std::pair <int, int> > v_Pairs;
	size_t n = v.size();

	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
			v_Pairs.push_back(std::make_pair(v[i], v[i + 1]));
		else
			v_Pairs.push_back(std::make_pair(v[i], -1));
	}
	return v_Pairs;
}

std::vector <int> PmergeMe::v_SortLarger(std::vector <std::pair <int, int> > &v_Pairs)
{
	size_t n = v_Pairs.size();
	if (n <= 1)
	{
		std::vector <int> v_Sorted;
		for (size_t i = 0; i < n; i++)
			v_Sorted.push_back(v_Pairs[i].first);
		return v_Sorted;
	}
	std::vector <int> v_Larger;
	for (size_t i = 0; i < n; i++)
		v_Larger.push_back(v_Pairs[i].first);
	std::vector <std::pair <int, int> > v_NewPairs = v_MakePairs(v_Larger);
	return v_SortLarger(v_NewPairs);
}

void	PmergeMe::v_Sort(int argc, char **argv)
{
	v_Init(argc, argv);
	std::vector <std::pair <int, int> > v_Pairs = v_MakePairs(v_MergeMe);
	size_t n = v_Pairs.size();
	for (size_t i = 0; i < n; i++)
	{
		v_Comparisons++;
		if (v_Pairs[i].first < v_Pairs[i].second)
			std::swap(v_Pairs[i].first, v_Pairs[i].second);
	}
	std::vector <int> v_Sorted = v_SortLarger(v_Pairs);
	for (size_t i = 0; i < v_Sorted.size(); i++)
		std::cout << v_Sorted[i] << " - ";
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

void	verifyInput(int argc, char **argv)
{		
	if (argc < 2)
			throw PmergeMe::Exception(errorMessage("not enough arguments"));
	std::vector <size_t> dupChecker;
	for (int i = 1; i < argc; i++)
	{
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
			throw PmergeMe::Exception(errorMessage("invalid element"));
		dupChecker.push_back(std::atoi(argv[i]));
	}
	std::vector <size_t>::iterator i;
	std::vector <size_t>::iterator j;
	for (i = dupChecker.begin(); i != dupChecker.end(); i++)
	{
		for (j = i + 1; j != dupChecker.end(); j++)
		{
			if (*j == *i)
				throw PmergeMe::Exception(errorMessage("found duplicate"));
		}
	}
}

std::string	errorMessage(const std::string &message)
{
	return "error: " + message;
}
