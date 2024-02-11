#include "../inc/easyfind.hpp"
#include <exception>
#include <vector>

const char	*NNotFound::what() const throw()
{
	return "Error: Value Not Found In Container";
}

void	tryVector()
{
 	bool				found = false;
	int					value = 0;
	std::vector	<int> 	map(26, 5);

	while (found == false)
	{
		try
		{
			easyfind(map, value);
			found = true;
			std::cout << "[" << value << "]" << " - Found In Container\n" << std::endl;
		}
		catch (const std::exception &notfound)
		{
			std::cerr << "[" << value << "] - " << notfound.what() << std::endl;
			value++;
		}
	}
}

void	tryList()
{
	std::list <int> lst;
	bool			found = false;
	int				value = 620;

	for (int i = 0; i < 7; i++)
		lst.push_back(i * i * i * i);
	while (found == false)
	{
		try
		{
			easyfind(lst, value);
			found = true;
			std::cout << "[" << value << "] - Found In Container\n" << std::endl; 
		}
		catch (const std::exception &notfound)
		{
			std::cerr << "[" << value << "] - " << notfound.what() << std::endl;
			value++;
		}
	}
}

int main()
{
	tryVector();
	tryList();
}