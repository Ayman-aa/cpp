#include "Contact.hpp"

// default constructor
Contact::Contact(void) {}

// deconstructor
Contact::~Contact(void){}

// displaying members' method
void Contact::printData(void)
{
	std::cout << "Displaying " << this->_nickName << "'s informations..." << std::endl;
	std::cout << "   First Name: " << this->_firstName << std::endl;
	std::cout << "   Last Name: " << this->_lastName << std::endl;
	std::cout << "   Nickname: " << this->_nickName << std::endl;
	std::cout << "   Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "   Darkest secret: " << this->_darkestSecret << std::endl;
}

//getter methods declaration
std::string Contact::getFirstName(void) const
{
    return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
    return (this->_lastName);
}

std::string Contact::getNickName(void) const
{
    return (this->_nickName);
}

std::string Contact::getPhoneNumber(void) const
{
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
    return (this->_darkestSecret);
}

//setter methods declaration
void Contact::setFirstName(std::string firstName)
{
    this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->_lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
    this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->_darkestSecret = darkestSecret;
}