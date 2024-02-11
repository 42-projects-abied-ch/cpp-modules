#include "Contact.hpp"

Contact::Contact()
{

}

int	Contact::AddNewContact(Contact *contact)
{
	std::string input;

	std::cout << "first name: ";
	while (input.length() < 1)
	{
		if (!(std::getline(std::cin, input)))
			return (1);
		if (!input[0])
		{
			std::cout << "input cannot be empty" << std::endl << "first name: ";
			continue;
		}	
	}
	contact->FirstName = input;
	input.erase();
	std::cout << "last name: ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
		if (!input[0])
		{
			std::cout << "input cannot be empty" << std::endl << "last name: ";
			continue;
		}	
	}
	contact->LastName = input;
	input.erase();
	std::cout << "nickname: ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
		if (!input[0])
		{
			std::cout << "input cannot be empty" << std::endl << "nickname: ";
			continue;
		}	
	}
	contact->NickName = input;
	input.erase();
	std::cout << "phone number: ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
		if (!input[0])
		{
			std::cout << "input cannot be empty" << std::endl << "phone number: ";
			continue;
		}	
	}
	contact->PhoneNumber = input;
	input.erase();
	std::cout << "darkest secret: ";
	while (input.length() < 1)
	{
		input.erase();
		if (!(std::getline(std::cin, input)))
			return (1);
		if (!input[0])
		{
			std::cout << "input cannot be empty" << std::endl << "darkest secret: ";
			continue;
		}	
	}
	contact->DarkestSecret = input;
	return (0);
}

void	Contact::ShowContact() const
{
	std::cout << "___________________________________________" << std::endl;
	std::cout << "first name: " << FirstName << std::endl;
	std::cout << "last name: "<< LastName << std::endl;
	std::cout << "nick name: "<< NickName << std::endl;
	std::cout << "phone number: "<< PhoneNumber << std::endl;
	std::cout << "darkest secret: "<< DarkestSecret << std::endl;
	std::cout << "___________________________________________" << std::endl;
}

void	Contact::ListContacts(int i) const
{
	std::cout << std::right << std::setw(10) << (i + 1) << "|";
	if (FirstName.size() > 10)
		std::cout << std::right << std::setw(9) << FirstName.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << FirstName.substr(0, 10) << "|";
	if (LastName.size() > 10)
		std::cout << std::right << std::setw(9) << LastName.substr(0, 9) << "." << "|";
	else
		std::cout << std::right << std::setw(10) << LastName.substr(0, 10) << "|";
	if (NickName.size() > 10)
		std::cout << std::right << std::setw(9) << NickName.substr(0, 9) << "." << "|" << std::endl;
	else
		std::cout << std::right << std::setw(10) << NickName.substr(0, 10) <<"|" << std::endl;
	
}
