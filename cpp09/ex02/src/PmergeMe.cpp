#include "../inc/PmergeMe.hpp"

// verifies input, initialize Jacobsthal constant & constructs the PmergeMe object
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

// std::exception constructor overload for simple & centralized error handling
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
