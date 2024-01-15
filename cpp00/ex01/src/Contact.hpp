#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <csignal>
#include <cstdlib>
#include <iomanip>

class Contact
{
	public:
		Contact();
		int		AddNewContact(Contact *contact);
		void	ShowContact() const;
		void	ListContacts(int i) const;
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
};

#endif