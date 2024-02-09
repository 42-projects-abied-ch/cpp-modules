#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# pragma once

# include <algorithm>
# include <iostream>
# include <map>
# include <fstream>
# include <exception>
# include <string>
# include <cctype>
# include <cstdlib>
# include <ctime>
# include <exception>
# include <fstream>
# include <sstream>

typedef enum e_validLine
{
	INVALID,
	VALID
}	t_validLine;

class BTCExchange
{
	private:

		std::map <std::string, float> 	dataBase;
		const std::string				todayDate;
		const std::string				inputFile;

		BTCExchange(const BTCExchange &other);
		BTCExchange();

	public:

		BTCExchange(const std::string &fileName);
		~BTCExchange();
		BTCExchange	&operator = (const BTCExchange &other);

		void			verifyInput(const std::string input);
		
		void			setDataBase();

		void			executeInput();

		void			checkLineDB(const std::string &line);
		void			processLineDB(const std::string &line);

		void			checkLineInput(const std::string &line);
		void			processLineInput(const std::string &line);
		void			checkConstants(const std::string &line);
		void	 		checkFloat(const std::string &line);
		std::string		checkDate(const std::string &line);
		void			printResult(const std::string &date, float n);

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

#endif