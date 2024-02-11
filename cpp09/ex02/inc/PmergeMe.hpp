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
# include <math.h>

class PmergeMe
{
	private:

		PmergeMe(const PmergeMe &other);

	public:

		PmergeMe();
		~PmergeMe();

		PmergeMe	&operator = (const PmergeMe &other);
		

		int						jacobsthal(int n);
		int						v_GetInsertionPoint(const std::vector <int> &v_MergeMe, int value);
		void					v_InsertionSort(std::vector <int> &v_MergeMe);
		void					v_Insert(std::vector <int> &_v_MergeMe, int value, int pos);
		void					v_MergeInsertionSort(std::vector <int> &v_MergeMe);
		void					v_Sort(int argc, char **argv);
		std::vector <int>		v_PendingElement(int n);
		std::vector <int>		v_Init(int argc, char **argv);



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