#include "../inc/BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <exception>
#include <sstream>

BTCExchange::BTCExchange()
{

}

BTCExchange::BTCExchange(const BTCExchange &other) : dataBase(other.dataBase)
{
	
}

BTCExchange::~BTCExchange()
{

}

BTCExchange	&BTCExchange::operator = (const BTCExchange &other)
{
	if (this == &other)
		return *this;
	this->dataBase = other.dataBase;
	return *this;
}

void	BTCExchange::setDataBase()
{
	std::ifstream dataBaseFile("database/data.csv");
	if (dataBaseFile.is_open() == true)
	{
		std::string line;

		while ((bool)std::getline(dataBaseFile, line) == true)
			processLineDB(line);
	}
	else
		throw BTCExchangeException("could not open database");
}

void	BTCExchange::checkLineDB(const std::string &line)
{
	if (line == "date,exchange_rate")
		return ;
	if (line.size() < 10 || line[4] != '-' || line[7] != '-')
		throw BTCExchangeException(line + " is invalid");
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (std::isdigit(line[i]) == false)
			break ;
	}
	if (line.size() < 11 || line[10] != ',')
		throw BTCExchangeException(line + " is invalid");
	std::string sRate = line.substr(11);
	char	*end;
	std::strtod(sRate.c_str(), &end);
	if (end == sRate.c_str() || *end != '\0')
		throw BTCExchangeException(line + " is invalid");
}

void	BTCExchange::processLineDB(const std::string &line)
{
	try
	{
		if (line == "date,exchange_rate")
			return ;
		checkLineDB(line);
		std::istringstream stringStream(line);
		std::string date;
		std::string sRate;
		std::getline(stringStream, date, ',');
		std::getline(stringStream, sRate, ',');
		float fRate = std::atof(sRate.c_str());
		this->dataBase[date] = fRate;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	BTCExchange::printDataBase()
{
	for (std::map<std::string, float>::const_iterator it = dataBase.begin(); it != dataBase.end(); ++it)
        std::cout << "Date: [" << it->first << "] - Rate: [" << it->second << "]" << std::endl;
}

BTCExchange::BTCExchangeException::BTCExchangeException(const std::string &message) : message("error: " + message)
{

}

BTCExchange::BTCExchangeException::~BTCExchangeException() throw()
{

}

const char	*BTCExchange::BTCExchangeException::what() const throw()
{
	return this->message.c_str();
}