#include "../inc/PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <deque>
#include <queue>
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
	for (int i = 1; i < argc; i++)
		v_MergeMe.push_back(std::atoi(argv[i]));
}

std::vector <int> PmergeMe::v_SortLarger(std::vector <std::pair <int, int> > &v_Pairs)
{
	std::vector <int> v_Larger;
	for (size_t i = 0; i < v_Pairs.size(); i++)
		v_Larger.push_back(v_Pairs[i].first);
	std::sort(v_Larger.begin(), v_Larger.end());
	if (v_Larger.size() > 1)
	{
		std::vector <std::pair <int, int> > v_NewPairs = v_MakePairs();
		return v_SortLarger(v_NewPairs);
	}
	else
		return v_Larger;
}

std::vector <int>	PmergeMe::v_SortSmaller(std::vector <std::pair <int, int> > &v_Pairs)
{
	std::vector <int> v_Smaller;
	for (size_t i = 0; i < v_Pairs.size(); i++)
		v_Smaller.push_back(v_Pairs[i].second);
	std::sort(v_Smaller.begin(), v_Smaller.end());
	if (v_Smaller.size() > 1)
	{
		std::vector <std::pair <int, int> > v_NewPairs = v_MakePairs();
		return v_SortSmaller(v_NewPairs);
	}
	else
		return v_Smaller;
}

std::vector <int>	PmergeMe::v_Merge(std::vector <int> v_1, std::vector <int> v_2)
{
	std::vector <int> v_Merged;
	while (v_1.empty() == false && v_2.empty() == false)
	{
		if (v_1.front() < v_2.front())
		{
			v_Merged.push_back(v_1.front());
			v_1.erase(v_1.begin());
		}
		else
		{
			v_Merged.push_back(v_2.front());
			v_2.erase(v_2.begin());
		}
	}
	while (v_1.empty() == false)
	{
		v_Merged.push_back(v_1.front());
		v_1.erase(v_1.begin());
	}
	while (v_2.empty() == false)
	{
		v_Merged.push_back(v_2.front());
		v_2.erase(v_2.begin());
	}
	return v_Merged;
}

void	PmergeMe::v_MergeSequences()
{
	std::vector <std::pair <int, int> > v_Pairs = v_MakePairs();
	std::vector <int> v_SortedLarger = v_SortLarger(v_Pairs);
	std::vector <int> v_SortedSmaller = v_SortSmaller(v_Pairs);
	v_MergeMe = v_Merge(v_SortedLarger, v_SortedSmaller);
}

std::vector <std::pair <int, int> >	PmergeMe::v_MakePairs()
{
	std::vector <std::pair <int, int> > v_Pairs;
	size_t n = v_MergeMe.size();
	std::sort(v_MergeMe.begin(), v_MergeMe.end());
	for (size_t i = 0; i < n; i += 2)
	{
		if (i + 1 < n)
			v_Pairs.push_back(std::make_pair(v_MergeMe[i], v_MergeMe[i + 1]));
		else
			v_Pairs.push_back(std::make_pair(v_MergeMe[i], -1));
	}
	return v_Pairs;
}

void	PmergeMe::v_Sort(int argc, char **argv)
{
	v_Init(argc, argv);
	std::vector <std::pair <int, int> > v_Pairs = v_MakePairs();
	v_MergeMe.clear();
	size_t n = v_Pairs.size();
	for (size_t i = 0; i < n; i++)
	{
		std::pair <int, int> v_TempPair = v_Pairs[i];
		if (v_TempPair.second != -1)
			v_MergeMe.insert(std::upper_bound(v_MergeMe.begin(), v_MergeMe.end(), v_TempPair.second), v_TempPair.second);
		v_MergeMe.insert(std::upper_bound(v_MergeMe.begin(), v_MergeMe.end(), v_TempPair.first), v_TempPair.first);
	}
	v_Print();
}

void	PmergeMe::v_Print()
{
	for (size_t i = 0; i < v_MergeMe.size(); i++)
	{
		std::cout << v_MergeMe[i];
		if (i < v_MergeMe.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
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
