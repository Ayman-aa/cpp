#include "PhoneBook.hpp"

// default constructor
PhoneBook::PhoneBook(void)
{
    this->_count = 0;
}

// deconstructor
PhoneBook::~PhoneBook(void) {}

// adding new contact method
void    PhoneBook::_addContact(Contact contact)
{
    if(this->_count >= 8)
        this->_count = 0;
    this->_contacts[this->_count++] = contact;
}

// displaying contacts method (prior to searching among them)
void	PhoneBook::_displayContacts(void) {
	std::ostringstream	oss;
	Contact				contact;
	int					i;
	const char			originalFill = std::cout.fill();

	i = 0;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::setfill(' ') \
			<< "|" << std::setw(10) << "index" \
			<< "|" << std::setw(10) << "first name" \
			<< "|" << std::setw(10) << "last name" \
			<< "|" << std::setw(10) << "nickname" \
			<< "|" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	while (i < 8)
	{
		contact = this->_contacts[i];
		if (contact.getFirstName().empty())
		{
			if (i == 0) std::cout << "|      You have no contacts registered.     |" << std::endl;
			break ;
		}
		oss.str("");
		oss.clear();
		oss << i;
		std::cout << std::setfill(' ') \
			<< "|" << std::setw(10) << _widthBar(oss.str()) \
			<< "|" << std::setw(10) << _widthBar(contact.getFirstName()) \
			<< "|" << std::setw(10) << _widthBar(contact.getLastName()) \
			<< "|" << std::setw(10) << _widthBar(contact.getNickName()) \
			<< "|" << std::setfill(originalFill) << std::endl;
		i++;
	}
	std::cout << "----------------------------------------" << std::endl;
}
