#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <ostream>
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
# include <bits/types/clock_t.h>
# include <cstddef>
# include <ctime>
# include <vector>
# include <iomanip>

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
		std::vector <int>		v_PendingElement(int n);
		std::vector <int>		v_Init(int argc, char **argv);
		void					v_FordJohnson(int argc, char **argv);

		int						d_GetInsertionPoint(const std::deque <int> &d_MergeMe, int value);
		void					d_InsertionSort(std::deque <int> &d_MergeMe);
		void					d_Insert(std::deque <int> &_d_MergeMe, int value, int pos);
		void					d_MergeInsertionSort(std::deque <int> &d_MergeMe);
		std::deque <int>		d_PendingElement(int n);
		std::deque <int>		d_Init(int argc, char **argv);
		void					d_FordJohnson(int argc, char **argv);

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

void				v_Print(std::vector <int> &v_MergeMe, const std::string &v_When);
void				d_Print(std::deque <int> &d_MergeMe, const std::string &d_When);

void				printResult(int c_ElemCount, const std::string &c_Type, double c_RunTime);

void				verifyInput(int argc, char **argv);
std::string			errorMessage(const std::string &message);

#endif