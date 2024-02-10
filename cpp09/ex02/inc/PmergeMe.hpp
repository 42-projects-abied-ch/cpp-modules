#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstddef>
# pragma once

# include <string>
# include <exception>
# include <vector>
# include <iostream>
# include <deque>
# include <algorithm>
# include <fstream>
# include <string>
# include <cctype>
# include <cstdlib>
# include <ctime>
# include <sstream>

class PmergeMe
{
	private:

		size_t				v_Comparisons;
		std::vector <int> 	v_MergeMe;
		std::deque	<int> 	D_mergeMe;

		PmergeMe(const PmergeMe &other);

	public:

		PmergeMe();
		~PmergeMe();

		PmergeMe	&operator = (const PmergeMe &other);

		void								v_Init(int argc, char **argv);
		void								v_Sort(int argc, char **argv);
		std::vector <std::pair <int, int> >	v_MakePairs();
		std::vector <int>					v_SortLarger(std::vector <std::pair <int, int> > &v_Pairs);
		std::vector <int>					v_SortSmaller(std::vector <std::pair <int, int> > &v_Pairs);
		std::vector <int>					v_Merge(std::vector <int> v_1, std::vector <int> v_2);
		void								v_MergeSequences();
		void								v_Print();

		class Exception : public std::exception
		{
			private:

				const std::string message;

			public:

				Exception(const std::string &message);
				virtual ~Exception() throw();
				virtual const char	*what() const throw();
		};
};

void				verifyInput(int argc, char **argv);
std::string			errorMessage(const std::string &message);

#endif