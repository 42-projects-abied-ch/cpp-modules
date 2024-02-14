#include "../inc/PmergeMe.hpp"

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
