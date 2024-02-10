#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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

		std::vector <int> V_mergeMe;
		std::deque	<int> D_mergeMe;

		PmergeMe(const PmergeMe &other);

	public:

		PmergeMe();
		~PmergeMe();

		PmergeMe	&operator = (const PmergeMe &other);

		void								vector_Init(int argc, char **argv);
		void								vector_Sort(int argc, char **argv);
		std::vector <std::pair <int, int>>	vector_MakePairs();


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