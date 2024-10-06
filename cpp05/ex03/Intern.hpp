#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &copy);
        ~Intern();
        Intern &operator=(const Intern &copy);

        AForm *makeForm(std::string formName, std::string target);
        AForm *createPresidentialPardonForm(std::string target);
        AForm *createRobotomyRequestForm(std::string target);
        AForm *createShrubberyCreationForm(std::string target);

        class FormNotFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif