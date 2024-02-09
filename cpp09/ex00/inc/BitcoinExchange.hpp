#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# pragma once

# include <algorithm>
# include <iostream>
# include <map>
# include <fstream>
# include <exception>
# include <string>

class BTCExchange
{
	private:

		std::map <std::string, float> 	dataBase;

		BTCExchange(const BTCExchange &other);

	public:

		BTCExchange();
		~BTCExchange();
		BTCExchange	&operator = (const BTCExchange &other);

		void			verifyInput(const std::string input);
		
		void			setDataBase();

		void			checkLineDB(const std::string &line);
		void			processLineDB(const std::string &line);

		void			checkLineInput(const std::string &line);
		void			processLineInput(const std::string &line);

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