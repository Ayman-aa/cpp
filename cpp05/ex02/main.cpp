#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        std::srand(std::time(0));
        Bureaucrat b1("b1", 50);
        Bureaucrat b2("b2", 1);
        ShrubberyCreationForm s1("s1");
        RobotomyRequestForm r1("r1");
        PresidentialPardonForm p1("p1");

        b1.signForm(s1);
        b1.signForm(r1);
        b1.signForm(p1);

        b2.signForm(r1);
        b2.signForm(p1);

        b1.executeForm(s1);
        b1.executeForm(r1);
        b1.executeForm(p1);

        b2.executeForm(r1);
        b2.executeForm(r1);
        b2.executeForm(r1);
        b2.executeForm(r1);
        b2.executeForm(p1);
        }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}