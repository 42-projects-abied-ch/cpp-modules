#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "enter command -- ADD/SEARCH/EXIT -- case sensitive" << std::endl;
		if (!(std::getline(std::cin, input)))
			return (1);
		if (input == "ADD")
		{
			Contact contact;
			if (phonebook.AddContact(contact))
				return (1);
		}
		else if (input == "SEARCH")
		{
			if (!phonebook.DisplayList(phonebook.ContactSize()))
			{
				std::cout << "enter index to get more information" << std::endl;
				while (true)
				{
					if (!(std::getline(std::cin, input)))
						return (1);
					if (std::atoi(input.c_str()) <= 8 && std::atoi(input.c_str()) >= 1)
					{
						phonebook.DisplayContact(std::atoi(input.c_str()) - 1);
						break ;
					}
					else
						std::cout << "0 < index < 9" << std::endl;
				}
			}
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "invalid input" << std::endl;
	}
	return (0);
}