#include "PhoneBook.hpp"

// default constructor
PhoneBook::PhoneBook(void)
{
    this->_count = 0;
}

// deconstructor
PhoneBook::~PhoneBook(void) {}

// helpers methods
// adding comprehensive text prompt to the user
std::string PhoneBook::_addPrompt(std::string prompt)
{
	std::string	input;
	std::cout << "   " << prompt << ": ";
	while (1)
	{
		if (!std::getline(std::cin, input)) {
			std::cout << "NULL" << std::endl;
			input = "NULL";
			break ;
		}
		if (!input.empty()) break ;
		if (!std::cin.eof()) std::cout << "   " << prompt << ": ";
	}
	return (input);
}

// fixing displayed text on 10 characters for more readability
std::string	PhoneBook::_widthBar(std::string str) {
	if ((int) str.length() > 10)
	{
		str = str.substr(0, 9);
		str.push_back('.');
	}
	return (str);
}

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
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "index" \
			<< "|" << std::setw(10) << "first name" \
			<< "|" << std::setw(10) << "last name" \
			<< "|" << std::setw(10) << "nickname" \
			<< "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (i < 8)
	{
		contact = this->_contacts[i];
		if (contact.getFirstName().empty())
		{
			if (i == 0) std::cout << "|      Oops no contacts registered.     |" << std::endl;
			break ;
		}
		oss.str("");
		oss.clear();
		oss << i;
		std::cout << "|" << std::setw(10) << _widthBar(oss.str()) \
			<< "|" << std::setw(10) << _widthBar(contact.getFirstName()) \
			<< "|" << std::setw(10) << _widthBar(contact.getLastName()) \
			<< "|" << std::setw(10) << _widthBar(contact.getNickName()) \
			<< "|" << std::setfill(originalFill) << std::endl;
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

// adding new contacts method
void PhoneBook::addContactPrompt(void)
{
	std::ostringstream	output;
	Contact				contact;

	// converting int _count to string using oss
	output << this->_count % 8;
	std::cout << "Adding new contact at index #" << output.str() << std::endl;

	if (this->_count >= 8)
		std::cout << "Overwriting oldest contact and adding more will overwite your contacts respectively" << std::endl;
	
	contact.setFirstName(_addPrompt("First name"));
	contact.setLastName(_addPrompt("Last name"));
	contact.setNickName(_addPrompt("Nickname"));
	contact.setPhoneNumber(_addPrompt("Phone number"));
	contact.setDarkestSecret(_addPrompt("Darkest secret"));

	_addContact(contact);
	std::cout << "Contact saved under nickname ' " << contact.getNickName() << " '" << std::endl;
}

void PhoneBook::searchPrompt(void)
{
	int			id;
	std::string input;
	bool 		validInput;

	if(!this->_count)
	{
		std::cout << "Try adding contacts before attempting to search among them" << std::endl;
		return ;
	}

	validInput = false;
	while (!validInput)
	{
        _displayContacts();
        std::cout << "Enter contact index (ID) or type cancel to exit" << std::endl;
        
        input = _addPrompt("Contact ID");
        if (input == "NULL")
            return ;

		if (input == "cancel" || input == "CANCEL")
		{
            std::cout << "Search cancelled." << std::endl;
            return;
        }

        validInput = true;
        for (size_t i = 0; i < input.length(); ++i)
		{
            if (!std::isdigit(input[i]))
			{
                std::cout << "This value is invalid. Please enter a number or cancel to exit." << std::endl;
                validInput = false;
                break ;
            }
        }
        
        if (validInput)
		{
            std::istringstream(input) >> id;
            if (id < 0 || id >= 8)
			{
                std::cout << "You can only display contacts from index 0 to 7." << std::endl;
                validInput = false;
                continue;
            }
            
            if (this->_contacts[id].getFirstName().empty())
			{
                std::cout << "This contact is unknown, please refer to your list." << std::endl;
                validInput = false;
                continue;
            }
            
            this->_contacts[id].printData();
        }
    }
}