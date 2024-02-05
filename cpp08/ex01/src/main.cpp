#include "../inc/Span.hpp"

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
	std::cout << "small.shortestSpan():\t[" << small.shortestSpan() << "]" << std::endl;
	std::cout << "small.longestSpan():\t[" << small.longestSpan() << "]" << std::endl;
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
	std::cout << "huge.shortestSpan():\t[" << huge.shortestSpan() << "]" << std::endl;
	std::cout << "huge.longestSpan():\t[" << huge.longestSpan() << "]" << std::endl;
}

int main()
{
	trySmall();
	tryHuge();
}