#include "../inc/PmergeMe.hpp"
#include <cstddef>
#include <deque>
#include <tuple>
#include <vector>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other) : V_mergeMe(other.V_mergeMe), D_mergeMe(other.D_mergeMe)
{

}

PmergeMe::~PmergeMe()
{

}

void	PmergeMe::vector_Init(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
		V_mergeMe.push_back(std::atoi(argv[i]));
}

std::vector <std::pair <int, int>>	PmergeMe::vector_MakePairs()
{
	std::vector <std::pair <int, int>> v_Pairs;
	size_t n = V_mergeMe.size();

	for (size_t i = 0; i < n; i += 2)
	{
		if (i + i < n)
			v_Pairs.push_back({V_mergeMe[i], V_mergeMe[i + 1]});
		else
			v_Pairs.push_back({V_mergeMe[i], -1});
	}
	return v_Pairs;
}

void	PmergeMe::vector_Sort(int argc, char **argv)
{
	vector_Init(argc, argv);
	std::vector <std::pair <int, int>> v_Pairs = vector_MakePairs();
	size_t n = v_Pairs.size();
	for (size_t i = 0; i < n; i++)
	{
		if (v_Pairs[i].first < v_Pairs[i].second)
			std::swap(v_Pairs[i].first, v_Pairs[i].second);
	}
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
