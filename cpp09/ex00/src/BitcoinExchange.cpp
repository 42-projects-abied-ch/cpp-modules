#include "../inc/BitcoinExchange.hpp"

BTCExchange::BTCExchange()
{

}

BTCExchange::BTCExchange(const BTCExchange &other) : dataBase(other.dataBase), todayDate(other.todayDate), inputFileName(other.inputFileName)
{

}

BTCExchange::BTCExchange(const std::string &fileName) : todayDate(getTodayDate()), inputFileName(fileName)
{

}

BTCExchange::~BTCExchange()
{

}

BTCExchange	&BTCExchange::operator = (const BTCExchange &other)
{
	if (this == &other)
		return *this;
	dataBase = other.dataBase;
	return *this;
}

std::string	BTCExchange::getTodayDate()
{
	char		date[11];
	std::time_t	t = std::time(0);
	std::tm		*now = std::localtime(&t);

	std::strftime(date, sizeof(date), "%Y-%m-%d", now);
	return std::string(date);
}

void	BTCExchange::verifyConstants(const std::string &line) const
{
	if (line.size() < MIN_SIZE_INPUT || line[MINUS_POS1] != '-' || line[MINUS_POS2] != '-')
		throw BTCExchangeException(formatError(line, INVALID_FORMAT));
	if (line[SPACE_POS1] != ' ' || line[PIPE_POS] != '|' || line[SPACE_POS2] != ' ')
		throw BTCExchangeException(formatError(line, INVALID_FORMAT));
}

void	BTCExchange::verifyNumberSize(const std::string &line) const
{
	if (line[INPUT_VAL_POS] == '-')
	{
		if (std::atof(line.substr(INPUT_VAL_POS + 1).c_str()) == 0)
			return ;
		throw BTCExchangeException(formatError(line.substr(INPUT_VAL_POS), NUM_NEGATIVE));
	}
	else if (std::atof(line.substr(INPUT_VAL_POS).c_str()) > 1000)
		throw BTCExchangeException(formatError(line.substr(INPUT_VAL_POS), NUM_TOO_HIGH));
}

void BTCExchange::verifyNumber(const std::string &line) const
{
	bool	decimal = false;
	bool	digit = false;
	size_t 	n = line.size();

	verifyNumberSize(line);
	for (size_t i = INPUT_VAL_POS; i < n; i++)
	{
		if (std::isdigit(line[i]) != false)
			digit = true;
		if (line[i] == '.')
		{
			if (decimal == true)
				throw BTCExchangeException(formatError(line.substr(INPUT_VAL_POS), NUM_INVALID));

			else
				decimal = true;
		}
		else if (std::isdigit(line[i]) == false)
			throw BTCExchangeException(formatError(line.substr(INPUT_VAL_POS), NUM_INVALID));
	}
	if (digit == false)
		throw BTCExchangeException(formatError(line.substr(INPUT_VAL_POS), NUM_INVALID));
}

bool	BTCExchange::isLeapYear(int year) const
{
	if (year % 4 != 0)
		return false;
	else if (year % 100 != 0)
		return true;
	else if (year % 400 != 0)
		return false;
	else
		return true;
}

void	BTCExchange::dateOverflow(const std::string &date) const
{
	int thirtyDays[] = { APRIL, JUNE, SEPTEMBER, NOVEMBER };
	int year = std::atoi(date.substr(0, MINUS_POS1).c_str());
	int month = std::atoi(date.substr(MINUS_POS1 + 1, MINUS_POS2).c_str());
	int day = std::atoi(date.substr(MINUS_POS2 + 1).c_str());
	if (month > 12)
		throw BTCExchangeException(formatError(month, MONTH_NOT_VALID));
	else if (day > 31)
		throw BTCExchangeException(formatError(day, DAY_NOT_VALID));
	else if (month == 2 && day > 28 + isLeapYear(year))
		throw BTCExchangeException(formatError(day, DAY_NOT_VALID));
	else if (day > 30 && std::find(thirtyDays, thirtyDays + sizeof(thirtyDays) / sizeof(thirtyDays[0]), month))
		throw BTCExchangeException(formatError(day, DAY_NOT_VALID));

}

std::string	BTCExchange::verifyDate(const std::string &line) const
{
	std::string date = line.substr(0, line.find(' '));

	for (size_t i = 0; i < date.size(); i++)
	{
		if (date[i] == '-')
			continue ;
		if (std::isdigit(date[i]) == 0)
			throw BTCExchangeException(formatError(date, DATE_INVALID_CHAR));
	}
	if (std::atoi(date.substr(0, date.find('-')).c_str()) < 1000)
		throw BTCExchangeException(formatError(date, DATE_FORMAT_INVALID));
	if (date > todayDate || std::atoi(date.substr(0, date.find('-')).c_str()) > 9999)
		throw BTCExchangeException(formatError(date, DATE_IN_FUTURE));
	if (date < dataBase.begin()->first)
		throw BTCExchangeException(formatError(date, DATE_TOO_EARLY));
	dateOverflow(date);
	return date;
}

void	BTCExchange::printResult(const std::string &date, float n)
{
	std::map<std::string, float>::iterator it = dataBase.upper_bound(date);
	--it;
	if (n == -0)
		n = 0;
	std::cout << date << " => " << n << " = " << n * it->second << std::endl;
}

void	BTCExchange::processLine_Input(const std::string &line)
{
	try
	{
		std::string date = verifyDate(line);
		verifyConstants(line);
		verifyNumber(line);
		printResult(date, std::atof(line.substr(INPUT_VAL_POS).c_str()));
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	BTCExchange::executeInput()
{
	std::ifstream inputFile(inputFileName.c_str());
	if (inputFile.is_open() == true)
	{
		std::string line;

		std::getline(inputFile, line);
		if (line != INPUT_EXPECTED_HEADER)
			throw BTCExchangeException(INPUT_INVALID_HEADER);
		while (std::getline(inputFile, line))
			processLine_Input(line);
		inputFile.close();
	}
	else
		throw BTCExchangeException(INPUT_FILE_OPEN);
}

void	BTCExchange::setDataBase()
{
	std::ifstream dataBaseFile(DATABASE);
	if (dataBaseFile.is_open() == true)
	{
		std::string line;

		std::getline(dataBaseFile, line);
		if (line.size() == 0)
			throw BTCExchangeException(DB_NO_HEADER);
		if (line != DB_EXPECTED_HEADER)
			throw BTCExchangeException(DB_INVALID_HEADER);
		while (std::getline(dataBaseFile, line))
			processLine_DB(line);
		dataBaseFile.close();
		if (this->dataBase.empty() == true)
			throw BTCExchangeException(DB_EMPTY);
	}
	else
		throw BTCExchangeException(DB_FILE_OPEN);
}

void	BTCExchange::verifyLine_DB(const std::string &line) const
{
	if (line.size() < MIN_SIZE_DB || line[MINUS_POS1] != '-' || line[MINUS_POS2] != '-')
		throw BTCExchangeException(line + " is invalid");
	for (size_t i = 0; i < 10; i++)
	{
		if (i == MINUS_POS1 || i == MINUS_POS2)
			continue ;
		if (std::isdigit(line[i]) == false)
			break ;
	}
	if (line[COMMA_POS] != ',')
		throw BTCExchangeException(line + " is invalid");
	std::string sRate = line.substr(DB_VAL_POS);
	char	*end;
	std::strtod(sRate.c_str(), &end);
	if (end == sRate.c_str() || *end != '\0')
		throw BTCExchangeException(line + " is invalid");
}

void	BTCExchange::processLine_DB(const std::string &line)
{
	verifyLine_DB(line);
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