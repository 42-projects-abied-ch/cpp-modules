#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>
# include <deque>
# include <iostream>
# include <vector>
# include <string>

typedef std::vector<int> vector;
typedef vector::iterator v_it;
typedef std::deque<int> deque;
typedef deque::iterator d_it;

class PmergeMe
{
	private:

		vector		v_mergeMe;
		deque		deque_;
		clock_t		v_sortTime;
		clock_t		d_sortTime_;

		int 		j_index;
		int 		jacobsthal[30];
		int 		insertCount;

		void 		setJacobsthal();
		int 		getNextIndex(int index);

		void		v_mergeInsert(int elemCount, int elemelemSize);
		void		v_sortPairs(int elemCount, int elemSize);
		void		v_makePairs(int elemCount, int elemSize, vector &main, vector &sub);
		void		v_insert(int elemCount, int elemSize, vector &main, vector &sub);
		void		v_binarySearch(vector &v_top, vector &v_bottom, size_t index, size_t elemSize);

		void		d_mergeInsert(int elemCount, int elemelemSize);
		void		d_sortPairs(int elemCount, int elemSize);
		void		d_makePairs(int elemCount, int elemSize, vector &main, vector &sub);
		void		d_insert(int elemCount, int elemSize, vector &main, vector &sub);
		void		d_binarySearch(vector &v_top, vector &v_bottom, size_t index, size_t elemSize);
		
		PmergeMe(const PmergeMe &);
		const 		PmergeMe &operator=(const PmergeMe &);

	public:

		~PmergeMe();
		PmergeMe();
		PmergeMe(int argc, char **argv);

		void 		v_sort();
		void 		d_sort();

		void		verifyInput(int argc, char **argv);

		void		printResult();

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

template <typename T>
void	printContainer(T &container)
{
	for (v_it it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T>
void	isSorted(T &container)
{
	for (size_t i = 0; i < container.size() - 1; i++)
	{
		if (container[i] > container[i + 1])
			throw PmergeMe::Exception("not sorted :(");
	}
	std::cout << "sorted :)" << std::endl;
}

#endif