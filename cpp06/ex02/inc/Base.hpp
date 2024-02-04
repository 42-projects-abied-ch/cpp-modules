#ifndef BASE_HPP
# define BASE_HPP

# pragma once

# include <cstdlib>
# include <ctime>
# include <iostream>

class Base
{
	public:

		virtual ~Base();
};

Base	*generate();
void	identify(Base *p);
void	identify(Base &p);

Base	*makeA();
Base	*makeB();
Base	*makeC();

#endif