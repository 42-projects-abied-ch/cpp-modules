#include "../inc/Span.hpp"
#include <cstddef>
#include <exception>

void	subjectMain()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	trySpans(Span span)
{
	try
	{
		size_t i = span.shortestSpan();
		std::cout << "shortestSpan:\t[" << i << "]" << std::endl;
	}
	catch (const std::exception &nospan)
	{
		std::cerr << nospan.what() << " - Size: [" << span.getN() << "]" << std::endl;
	}
	try
	{
		size_t i = span.longestSpan();
		std::cout << "longestSpan:[" << i << "]" << std::endl;
	}
	catch (const std::exception &nospan)
	{
		std::cerr << nospan.what() << " - Size: [" << span.getN() << "]" << std::endl;
	}
}

void	trySmall()
{
	Span small(10);
	bool alreadyFull = false;
	int	value = 0;

	while (alreadyFull == false)
	{
		try
		{
			small.addNumber(value);
			value++;
		}
		catch (const std::exception &full)
		{
			std::cerr << full.what() << " - Size: [" << small.getN() << "]" << std::endl;
			alreadyFull = true;
		}
	}
	trySpans(small);
}

void	tryHuge()
{
	Span huge(1000000);
	bool alreadyFull = false;
	int	value = 0;

	while (alreadyFull == false)
	{
		try
		{
			huge.addNumber(value);
			value++;
		}
		catch (const std::exception &full)
		{
			std::cerr << full.what() << " - Size: [" << huge.getN() << "]" << std::endl;
			alreadyFull = true;
		}
	}
	trySpans(huge);
}

void	tryEmpty()
{
	Span empty(0);
	bool alreadyFull = false;
	int	value = 0;

	while (alreadyFull == false)
	{
		try
		{
			empty.addNumber(value);
			value++;
		}
		catch (const std::exception &full)
		{
			std::cerr << full.what() << " - Size: [" << empty.getN() << "]" << std::endl;
			alreadyFull = true;
		}
	}
	trySpans(empty);
}

int main()
{
	std::cout << "--- Testing With Small Container ---\n" << std::endl;
	trySmall();
	std::cout << "\n--- Testing With Big Ass Container ---\n" << std::endl;
	tryHuge();
	std::cout << "\n--- Testing With Empty Container ---\n" << std::endl;
	tryEmpty();
	std::cout << "\n--- Main From Subject ---\n" << std::endl;
	subjectMain();
}