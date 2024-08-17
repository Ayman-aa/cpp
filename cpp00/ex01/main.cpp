#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   phonebook;
    std::string input;

    std::cout << "Welcome to the 80s and their unbelievable technology" << std::endl;

    while (1)
    {
        if (!std::cin.eof())
            std::cout << "COMMAND > ";

        if (!std::getline(std::cin, input))
        {
            std::cout << "EXIT" << std::endl;
            break ;
        }

        if (!input.compare("ADD") || !input.compare("add"))
            phonebook.addContactPrompt();

        else if (!input.compare("SEARCH") || !input.compare("search"))
            phonebook.searchPrompt();
        
        else if (!input.compare("EXIT") || !input.compare("exit"))
            break ;
    }
    std::cout << "Exiting program" << std::endl;
    return 0;
}