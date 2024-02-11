#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe::~PmergeMe()
{

}

int		PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int prev = 0;
	int curr = 1;
	for (int i = 2; i <= n; ++i)
	{
		int next = prev + 2 * curr;
		prev = curr;
		curr = next;
	}
	return curr;
}

int		PmergeMe::v_GetInsertionPoint(const std::vector <int> &v_MergeMe, int value)
{
	int low = 0; 
	int high = v_MergeMe.size() - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (v_MergeMe[mid] < value)
			low = mid + 1;
		else if (value < v_MergeMe[mid])
			high = mid - 1;
		else
			return mid;
	}
	return low;
}

void	PmergeMe::v_InsertionSort(std::vector <int> &v_MergeMe)
{
	for (size_t i = 0; i < v_MergeMe.size(); i++)
	{
		int key = v_MergeMe[i];
		int j = i - 1;

		while (j >= 0 && key < v_MergeMe[j])
		{
			v_MergeMe[j + 1] = v_MergeMe[j];
			j--;
		}
		v_MergeMe[j + 1] = key;
	}
}

void	PmergeMe::v_Insert(std::vector <int> &v_MergeMe, int value, int pos)
{
	v_MergeMe.insert(v_MergeMe.begin() + pos, value);
}

std::vector <int>	PmergeMe::v_PendingElement(int n)
{
	std::vector <int> v_Order;
	
	for (int i = 0;; i++)
	{
		int j = jacobsthal(i);
		if (j >= n)
			break ;
		v_Order.push_back(j);
	}
	v_Order.push_back(n);
	std::vector <int> v_FinalOrder;
	for (size_t i = 0; i + 1 < v_Order.size(); i += 2)
	{
		for (int j = v_Order[i + 1]; j >= v_Order[i]; j--)
			v_FinalOrder.push_back(j);
	}
	return v_FinalOrder;
}

void	PmergeMe::v_MergeInsertionSort(std::vector <int> &v_MergeMe)
{
	if (v_MergeMe.size() < 2)
		return ;
	std::vector <int> v_Sorted, v_Pending;
	for (size_t i = 0; i < v_MergeMe.size(); i += 2)
	{
		if (i + 1 < v_MergeMe.size())
		{
			if (v_MergeMe[i] < v_MergeMe[i + 1])
			{
				v_Sorted.push_back(v_MergeMe[i]);
				v_Pending.push_back(v_MergeMe[i + 1]);
			}
			else
			{
				v_Sorted.push_back(v_MergeMe[i + 1]);
				v_Pending.push_back(v_MergeMe[i]);
			}
		}
		else
			v_Pending.push_back(v_MergeMe[i]);
	}
	v_InsertionSort(v_Sorted);
	std::vector <int> v_Order = v_PendingElement(v_Pending.size());
	for (size_t i = 0; i < v_Order.size(); i++)
	{
		int pos = v_GetInsertionPoint(v_Sorted, v_Pending[v_Order[i]]);
		std::cout << "i: " << i << " - v_Order[i]: " << v_Order[i] <<" - "<< v_Pending[v_Order[i]] << std::endl;
		if ((size_t)v_Order[i] < v_Pending.size())
			v_Insert(v_Sorted, v_Pending[v_Order[i]], pos);
	}
	v_MergeMe = v_Sorted;
}

std::vector <int>	PmergeMe::v_Init(int argc, char **argv)
{
	std::vector <int> v_MergeMe;

	for (int i = 1; i < argc; i++)
		v_MergeMe.push_back(std::atoi(argv[i]));
	return v_MergeMe;
}

void	PmergeMe::v_Sort(int argc, char **argv)
{
	std::vector <int> v_MergeMe = v_Init(argc, argv);
	v_MergeInsertionSort(v_MergeMe);

	for (size_t i = 0; i < v_MergeMe.size(); ++i)
	{
		std::cout << v_MergeMe[i];
		if (i < v_MergeMe.size() - 1)
			std::cout << " ";
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
