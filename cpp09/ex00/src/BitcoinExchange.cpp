#include "../inc/BitcoinExchange.hpp"
#include <cctype>

BTCExchange::BTCExchange()
{

}

BTCExchange::BTCExchange(const BTCExchange &other) : dataBase(other.dataBase)
{

}

BTCExchange::BTCExchange(const std::string &fileName) : todayDate(this->getTodayDate()), inputFile(fileName)
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

std::string	BTCExchange::getTodayDate()
{
	std::time_t	t = std::time(0);
	std::tm		*now = std::localtime(&t);
	char	buf[11];
	std::strftime(buf, sizeof(buf), "%Y-%m-%d", now);
	return std::string(buf);
}

void	BTCExchange::checkConstants(const std::string &line)
{
	if (line.size() < 14 || line[4] != '-' || line[7] != '-')
		throw BTCExchangeException("[" + line + "]: is not a valid input format");
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw BTCExchangeException("[" + line + "]: is not a valid input format");
}

void BTCExchange::checkFloat(const std::string &line)
{
	size_t n = line.size();
	bool	decimal = false;
	bool	digit = false;
	
	if (line[13] == '-')
	{
		if (std::atof(line.substr(14).c_str()) == 0)
			return ;
		throw BTCExchangeException("[" + line.substr(13) + "]: negative numbers are not supported");
	}
	else if (std::atof(line.substr(13).c_str()) > 1000)
		throw BTCExchangeException("[" + line.substr(13) + "]: number too high (max 1000)");
	for (size_t i = 13; i < n; i++)
	{
		if (std::isdigit(line[i]) != false)
			digit = true;
		if (line[i] == '.')
		{
			if (decimal == true)
				throw BTCExchangeException("[" + line.substr(13) + "]: is not a valid number");
			else
				decimal = true;
		}
		else if (std::isdigit(line[i]) == false)
			throw BTCExchangeException("[" + line.substr(13) + "]: is not a valid number");
	}
	if (digit == false)
		throw BTCExchangeException("[" + line.substr(13) + "]: is not a valid number");
}

std::string	BTCExchange::checkDate(const std::string &line)
{
	std::string date = line.substr(0, line.find(' '));

	if (std::atoi(date.substr(0, date.find('-')).c_str()) < 1000)
		throw BTCExchangeException("[" + date + "]: invalid date format (YYYY-MM-DD)");
	if (date > this->todayDate || std::atoi(date.substr(0, date.find('-')).c_str()) > 9999)
		throw BTCExchangeException("[" + date + "]: date is in the future");
	else if (date < this->dataBase.begin()->first)
		throw BTCExchangeException("[" + date + "]: date is earlier than first one in database");
	return date;
}

void	BTCExchange::printResult(const std::string &date, float n)
{
	std::map<std::string, float>::iterator it = this->dataBase.upper_bound(date);
	--it;
	if (n == -0)
		n = 0;
	std::cout << date << " => " << n << " = " << n * it->second << std::endl;
}

void	BTCExchange::processLineInput(const std::string &line)
{
	try
	{
		checkConstants(line);
		checkFloat(line);
		std::string date = checkDate(line);
		printResult(line.substr(0, 10), std::atof(line.substr(13).c_str()));
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	BTCExchange::executeInput()
{
	std::ifstream inputFile(this->inputFile.c_str());
	if (inputFile.is_open() == true)
	{
		std::string line;

		std::getline(inputFile, line);
		if (line != "date | value")
			throw BTCExchangeException("input file header is invalid");
		while ((bool)std::getline(inputFile, line) == true)
			processLineInput(line);
	}
	else
		throw BTCExchangeException("could not open input file");
}

void	BTCExchange::setDataBase()
{
	std::ifstream dataBaseFile("database/data.csv");
	if (dataBaseFile.is_open() == true)
	{
		std::string line;

		std::getline(dataBaseFile, line);
		if (line != "date,exchange_rate")
			throw BTCExchangeException("database header is invalid");
		while ((bool)std::getline(dataBaseFile, line) == true)
			processLineDB(line);
		if (this->dataBase.empty() == true)
			throw BTCExchangeException("database is empty");
	}
	else
		throw BTCExchangeException("could not open database");
}

void	BTCExchange::checkLineDB(const std::string &line)
{
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
	checkLineDB(line);
	std::istringstream stringStream(line);
	std::string date;
	std::string sRate;
	std::getline(stringStream, date, ',');
	std::getline(stringStream, sRate, ',');
	float fRate = std::atof(sRate.c_str());
	this->dataBase[date] = fRate;
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