#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# pragma once

# include <exception>
# include <iostream>
# include <list>
# include <vector>
# include <iterator>
# include <algorithm>

class NNotFound : public std::exception
{
	virtual const char	*what() const throw();
};

template <typename T>
int	easyfind(const T &container, int n)
{
	typename T::const_iterator finder = std::find(container.begin(), container.end(), n);

	if (finder == container.end())
		throw NNotFound();
	else
		return *finder;
}

#endif