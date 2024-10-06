#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *(Intern::*formCreators[3])(std::string) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
