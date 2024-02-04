#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <cstddef>
#include <exception>

size_t	srandSeed = 0;

Base::~Base()
{

}

Base	*makeA()
{
	return new A;
}

Base	*makeB()
{
	return new B;
}

Base	*makeC()
{
	return new C;
}


Base	*generate()
{
	Base	*(*makers[])() = { &makeA, &makeB, &makeC };
    
	srand(static_cast<unsigned int>(time(NULL) + srandSeed));
	srandSeed++;
    int    ABC = rand() % 3;
	
	return makers[ABC]();
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Object Pointer Is From Class A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Object Pointer Is From Class B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Object Pointer Is From Class C" << std::endl;
	else
		std::cout << "Could Not Identify Object Pointer" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		Base temp = dynamic_cast<A &>(p);
		(void)temp;
		std::cout << "Object Reference Is From Class A" << std::endl;
	}
	catch (std::exception &badCast)
	{

	}
	try
	{
		Base temp = dynamic_cast<B &>(p);
		(void)temp;
		std::cout << "Object Reference Is From Class B" << std::endl;
	}
	catch (std::exception &badCast)
	{

	}
	try
	{
		Base temp = dynamic_cast<C &>(p);
		(void)temp;
		std::cout << "Object Reference Is From Class C" << std::endl;
	}
	catch (std::exception &badCast)
	{

	}
}

