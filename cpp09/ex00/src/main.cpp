#include "../inc/BitcoinExchange.hpp"
#include <cstdlib>
#include <exception>

int	checkArgumentCount(int argc)
{
	try
	{
		if (argc != 2)
			throw BTCExchange::BTCExchangeException("execution: ./btc input.csv");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
	if (checkArgumentCount(argc) == EXIT_FAILURE)
		return EXIT_FAILURE;
	BTCExchange btc(argv[1]);
	try
	{
		btc.setDataBase();
		btc.executeInput();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}