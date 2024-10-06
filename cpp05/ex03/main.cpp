#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
   try
   {
        Bureaucrat b1("b1", 1);
        Intern intern;
        AForm *form1 = intern.makeForm("presidential pardon", "target1");
        AForm *form2 = intern.makeForm("robotomy request", "target2");
        AForm *form3 = intern.makeForm("shrubbery creation", "target3");

        b1.signForm(*form1);
        b1.signForm(*form2);
        b1.signForm(*form3);

        b1.executeForm(*form1);
        b1.executeForm(*form2);
        b1.executeForm(*form3);

        delete form1;
        delete form2;
        delete form3;
   }
   catch (std::exception &e)
   {
       std::cerr << e.what() << std::endl;
   }
}