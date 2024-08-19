# include <iostream>

int main(void)
{
    std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	// Init
	std::cout << "Initial value of string: " << string << std::endl;

	// Printing addresses
	std::cout << "Printing addresses..."  << std::endl;
	std::cout << "Memory address of string variable: " << &string << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	// Printing data
	std::cout << "Printing content..."  << std::endl;
	std::cout << "Value of string variable: " << string << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF: " << stringREF << std::endl;
	return (0);
}