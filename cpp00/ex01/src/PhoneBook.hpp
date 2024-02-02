#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:

	PhoneBook();
	~PhoneBook();
	int		AddContact(Contact contact);
	int		DisplayList(int nbr_contact) const;
	void	DisplayContact(int index) const;
	int		CurrentIndex() const;
	int		ContactSize() const;

	private:

	int index;
	int	ContactAmount;
	Contact _Contacts[8];
};

#endif