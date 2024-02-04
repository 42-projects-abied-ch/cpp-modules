#ifndef DATASTRUCTURE_HPP
# define DATASTRUCTURE_HPP

# pragma once

# include <iostream>

typedef struct s_DataStructure
{
	std::string 	fullName;
	std::string		birthDate;
	size_t			day;
	size_t			month;
	size_t			year;
}	t_DataStructure;

#endif