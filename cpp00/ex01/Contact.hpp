#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstring>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        /* Constructors & Destructors */
        Contact(void);
        ~Contact(void);

        /* Methods */
        void        printData(void);

        /* Getters*/
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickName(void) const;
        std::string getPhoneNumber(void) const;
        std::string getDarkestSecret(void) const;

        /* Setters */
        void        setFirstName(std::string firstName);
        void        setLastName(std::string lastName);
        void        setNickName(std::string nickName);
        void        setPhoneNumber(std::string phoneNumber);
        void        setDarkestSecret(std::string darkestSecret);
};

#endif