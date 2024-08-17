#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <sstream>
# include <iomanip>

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _count;

        /* Private Methods */
        void            _addContact(Contact contact);
        void            _displayContacts(void);
        std::string     _addPrompt(std::string str);
        std::string     _widthBar(std::string str);
        bool            _isAllPrintable(const std::string& str);

    public:

        /* Constructors & Destructors */
        PhoneBook(void);
        ~PhoneBook(void);

        /* Methods */
        void                addContactPrompt(void);
        void				searchPrompt(void);

};

#endif