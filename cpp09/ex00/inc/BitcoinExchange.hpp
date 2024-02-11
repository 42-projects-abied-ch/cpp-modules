#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# pragma once


# include "Defines.h"
# include "Headers.h"

class BTCExchange
{
	private:

		std::map <std::string, float> 	dataBase;
		const std::string				todayDate;
		const std::string				inputFileName;

		BTCExchange(const BTCExchange &other);
		BTCExchange();

	public:

		BTCExchange(const std::string &fileName);
		~BTCExchange();
		BTCExchange	&operator = (const BTCExchange &other);

		void			setDataBase();

		void			executeInput();

		void			verifyLine_DB(const std::string &line) const;
		void			processLine_DB(const std::string &line);

		void			verifyConstants(const std::string &line) const;

		void			verifyLine_Input(const std::string &line) const;
		void			processLine_Input(const std::string &line);
		
		void	 		verifyNumber(const std::string &line) const;
		void			verifyNumberSize(const std::string &line) const;

		std::string		verifyDate(const std::string &line) const;
		void			printResult(const std::string &date, float n);
		void			dateOverflow(const std::string &date) const;
		bool			isLeapYear(int year) const;

		std::string		getTodayDate();

		void			printDataBase();

		class BTCExchangeException : public std::exception
		{
			private:

				const std::string message;

			public:

				BTCExchangeException(const std::string &message);
				virtual ~BTCExchangeException() throw();
				virtual const char	*what() const throw();
		};
};

template <typename T>
std::string	formatError(T errorValue, const std::string errorMessage)
{
	std::ostringstream oss;
	oss << errorValue;
	return "[" + oss.str() + "]: " + errorMessage;
}

#endif