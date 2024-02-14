#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>
# include <deque>
# include <iostream>
# include <vector>
# include <string>
# include <cstdlib>

// typedefs for shorter lines
typedef std::vector<int>	vector;
typedef vector::iterator	v_it;
typedef std::deque<int>		deque;
typedef deque::iterator		d_it;

// defines for constants/error messages
# define VEC_TYPE "std::vector"
# define DEQ_TYPE "std::deque"
# define ERR_NOT_SORTED "input not sorted correctly, guess i will retry in 3 days"
# define ERR_SORTED "input already sorted"
# define ERR_ARGC "not enough arguments"
# define ERR_INVALID "invalid element"
# define ERROR "error: "

class PmergeMe
{
	private:

		// track comparisons by adding this to each if condition's body
		int			comparisons;

		vector		v_mergeMe;
		deque		d_mergeMe;

		int 		j_index;
		// store the jacobsthal sequence in an integer array instead of computing it every time
		int 		jacobsthal[30];
		// keep tracf numbers
		int 		insertCount;

		void 		setJacobsthal();
		int 		getNextIndex(int index);

		void		v_init(int argc, char **argv);
		void		v_mergeInsert(int elemCount, int elemelemSize);
		void		v_sortPairs(int elemCount, int elemSize);
		void		v_makePairs(int elemCount, int elemSize, vector &main, vector &sub);
		void		v_insert(int elemCount, int elemSize, vector &main, vector &sub);
		void		v_binarySearch(vector &v_top, vector &v_bottom, size_t index, size_t elemSize);

		void		d_init(int argc, char **argv);
		void		d_mergeInsert(int elemCount, int elemelemSize);
		void		d_sortPairs(int elemCount, int elemSize);
		void		d_makePairs(int elemCount, int elemSize, deque &main, deque &sub);
		void		d_insert(int elemCount, int elemSize, deque &main, deque &sub);
		void		d_binarySearch(deque &v_top, deque &v_bottom, size_t index, size_t elemSize);
		
		PmergeMe(const PmergeMe &);
		const 		PmergeMe &operator=(const PmergeMe &);

	public:

		~PmergeMe();
		PmergeMe();
		PmergeMe(int argc, char **argv);

		void 		v_sort(int argc, char **argv);
		void 		d_sort(int argc, char **argv);

		void		verifyInput(int argc, char **argv);

		class Exception : public std::exception
		{
			private:

				const std::string 		message;

			public:

				Exception(const std::string &message);
				virtual ~Exception() 	throw();
				virtual const char		*what() const throw();
		};
};

std::string	errorMessage(const std::string &message);

template <typename T>
void	printContainer(T &container, const std::string &what, const std::string &when)
{
	if (what != ERR_SORTED)
		std::cout << what << " " << when << ":\n[";
	else
		std::cout << "[";
	for (size_t i = 0; i < container.size(); i++)
	{
		std::cout << container[i];
		if (i < container.size() - 1)
			std::cout  << ", ";
	}	
	std::cout << "]" << std::endl;
}

template <typename T>
bool	isSorted(T &container)
{
	for (size_t i = 0; i < container.size() - 1; i++)
	{
		if (container[i] > container[i + 1])
			return false;
	}
	return true;
}

void printResult(const int count, const std::string &what, const clock_t &time, int comparisons);

#endif