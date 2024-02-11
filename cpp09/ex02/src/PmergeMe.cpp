#include "../inc/PmergeMe.hpp"
#include <deque>
#include <iomanip>
#include <ostream>
#include <vector>

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

void	PmergeMe::v_FordJohnson(int argc, char **argv)
{
	clock_t	start = clock();
	std::vector <int> v_MergeMe = v_Init(argc, argv);
	v_Print(v_MergeMe, "before");
	v_MergeInsertionSort(v_MergeMe);
	v_Print(v_MergeMe, "after");
	clock_t end = clock();
	printResult(argc - 1, "std::vector", (double)(end - start) / CLOCKS_PER_SEC * 1000000);
}

int		PmergeMe::d_GetInsertionPoint(const std::deque <int> &d_MergeMe, int value)
{
	int low = 0; 
	int high = d_MergeMe.size() - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (d_MergeMe[mid] < value)
			low = mid + 1;
		else if (value < d_MergeMe[mid])
			high = mid - 1;
		else
			return mid;
	}
	return low;
}

void	PmergeMe::d_InsertionSort(std::deque <int> &d_MergeMe)
{
	for (size_t i = 0; i < d_MergeMe.size(); i++)
	{
		int key = d_MergeMe[i];
		int j = i - 1;

		while (j >= 0 && key < d_MergeMe[j])
		{
			d_MergeMe[j + 1] = d_MergeMe[j];
			j--;
		}
		d_MergeMe[j + 1] = key;
	}
}

void	PmergeMe::d_Insert(std::deque <int> &d_MergeMe, int value, int pos)
{
	d_MergeMe.insert(d_MergeMe.begin() + pos, value);
}

std::deque <int>	PmergeMe::d_PendingElement(int n)
{
	std::deque <int> d_Order;
	
	for (int i = 0;; i++)
	{
		int j = jacobsthal(i);
		if (j >= n)
			break ;
		d_Order.push_back(j);
	}
	d_Order.push_back(n);
	std::deque <int> d_FinalOrder;
	for (size_t i = 0; i + 1 < d_Order.size(); i += 2)
	{
		for (int j = d_Order[i + 1]; j >= d_Order[i]; j--)
			d_FinalOrder.push_back(j);
	}
	return d_FinalOrder;
}

void	PmergeMe::d_MergeInsertionSort(std::deque <int> &d_MergeMe)
{
	if (d_MergeMe.size() < 2)
		return ;
	std::deque <int> d_Sorted, d_Pending;
	for (size_t i = 0; i < d_MergeMe.size(); i += 2)
	{
		if (i + 1 < d_MergeMe.size())
		{
			if (d_MergeMe[i] < d_MergeMe[i + 1])
			{
				d_Sorted.push_back(d_MergeMe[i]);
				d_Pending.push_back(d_MergeMe[i + 1]);
			}
			else
			{
				d_Sorted.push_back(d_MergeMe[i + 1]);
				d_Pending.push_back(d_MergeMe[i]);
			}
		}
		else
			d_Pending.push_back(d_MergeMe[i]);
	}
	d_InsertionSort(d_Sorted);
	std::deque <int> d_Order = d_PendingElement(d_Pending.size());
	for (size_t i = 0; i < d_Order.size(); i++)
	{
		int pos = d_GetInsertionPoint(d_Sorted, d_Pending[d_Order[i]]);
		if ((size_t)d_Order[i] < d_Pending.size())
			d_Insert(d_Sorted, d_Pending[d_Order[i]], pos);
	}
	d_MergeMe = d_Sorted;
}

std::deque <int>	PmergeMe::d_Init(int argc, char **argv)
{
	std::deque <int> d_MergeMe;

	for (int i = 1; i < argc; i++)
		d_MergeMe.push_back(std::atoi(argv[i]));
	return d_MergeMe;
}

void	PmergeMe::d_FordJohnson(int argc, char **argv)
{
	clock_t	start = clock();
	std::deque <int> d_MergeMe = d_Init(argc, argv);
	d_Print(d_MergeMe, "before");
	d_MergeInsertionSort(d_MergeMe);
	d_Print(d_MergeMe, "after");
	clock_t end = clock();
	printResult(argc - 1, "std::deque", (double)(end - start) / CLOCKS_PER_SEC * 1000000);
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

void	printResult(int c_ElemCount, const std::string &c_Type, double c_RunTime)
{
	std::cout << "time to process a range of [" << c_ElemCount << "] elements ";
	std::cout << "with " << c_Type << ": ";
	std::cout << std::fixed << std::setprecision(1) <<  c_RunTime << " μs" << std::endl;
}

void	d_Print(std::deque<int> &d_MergeMe, const std::string &d_When)
{
	std::cout << std::endl;
	std::cout << d_When << ":" << std::endl;
	for (size_t i = 0; i < d_MergeMe.size(); ++i)
	{
		std::cout << d_MergeMe[i];
		if (i < d_MergeMe.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl << std::endl;
}

void	v_Print(std::vector<int> &d_MergeMe, const std::string &d_When)
{
	std::cout << d_When << ":" << std::endl;
	for (size_t i = 0; i < d_MergeMe.size(); ++i)
	{
		std::cout << d_MergeMe[i];
		if (i < d_MergeMe.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl << std::endl;
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
}

std::string	errorMessage(const std::string &message)
{
	return "error: " + message;
}
