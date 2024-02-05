#ifndef SPAN_HPP
# define SPAN_HPP

# pragma once

# include <cstddef>
# include <exception>
# include <iostream>
# include <vector>
# include <algorithm>
# include <set>
# include <stdint.h>

class Span
{
	private:

		size_t				N;
		std::vector <int>		storage;

		Span();
		Span(const Span &other);

	public:

		Span(size_t _N);
		~Span();

		Span	&operator = (const Span &other);

		void				addNumber(int n);
		int					shortestSpan();
		int					longestSpan();

		size_t				getN() const;

		class AlreadyFull : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class NoSpanFound : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

#endif