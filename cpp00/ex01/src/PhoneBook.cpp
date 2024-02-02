
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), ContactAmount(0)
{

}

PhoneBook::~PhoneBook()
{
	
}

int	PhoneBook::CurrentIndex() const
{
	return (index);
}

int	PhoneBook::ContactSize() const
{
	return (ContactAmount);
}

int	PhoneBook::AddContact(Contact _Contact)
{
	if (index + 1 > 8)
		index = 0;
	if (_Contact.AddNewContact(&_Contacts[index]))
		return (1);
	index++;
	if (ContactAmount < 8)
		ContactAmount++;
	return (0);
}

void PhoneBook::DisplayContact(int i) const
{
	_Contacts[i].ShowContact();
}

int PhoneBook::DisplayList(int max) const
{
	if (max == 0)
	{
		std::cout << std::right << "phone book empty" << std::endl;
		return (1);
	}
	std::cout << "|    index|first name| last name|  nickname|" << std::endl;
	std::cout << "|__________________________________________|" << std::endl << std::endl;
	int i = -1;
	while (++i < max)
		_Contacts[i].ListContacts(i);
	std::cout << "|__________________________________________|" << std::endl;
	return (0);
}