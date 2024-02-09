#include "../inc/BitcoinExchange.hpp"
#include <cstdlib>
#include <exception>

void	checkArgumentCount(int argc)
{
	try
	{
		if (argc != 2)
			throw BTCExchange::BTCExchangeException("execution: ./btc input.csv");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	checkArgumentCount(argc);
	BTCExchange btc(argv[1]);
	try
	{
		btc.setDataBase();
		btc.executeInput();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}