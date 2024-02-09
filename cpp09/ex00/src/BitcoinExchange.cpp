#include "../inc/BitcoinExchange.hpp"
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
			processLine(line);
	}
	else
		throw BTCExchangeException("could not open database");
}

void	BTCExchange::processLine(const std::string &line)
{
	if (line == "date,exchange_rate")
		return ;
	else
	{
		std::istringstream stringStream(line);
		std::string date;
		std::string sRate;
		std::getline(stringStream, date, ',');
		std::getline(stringStream, sRate, ',');
		float fRate = std::atof(sRate.c_str());
		this->dataBase[date] = fRate;
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