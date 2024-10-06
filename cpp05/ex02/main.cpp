#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat highRanking("Alice", 1);
        Form formA("FormA", 1, 1);
        std::cout << formA << std::endl;

        // Signing the form
        formA.beSigned(highRanking);
        std::cout << formA << std::endl;

        // This should throw an exception
        highRanking.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Bureaucrat error: " << e.what() << std::endl;
    } catch (const Form::GradeTooHighException& e) {
        std::cout << "Form error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat lowRanking("Bob", 150);
        Form formB("FormB", 150, 150);
        std::cout << formB << std::endl;

        // Signing the form
        lowRanking.signForm(formB);
        std::cout << formB << std::endl;

        // This should throw an exception
        lowRanking.decrementGrade();
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Bureaucrat error: " << e.what() << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << "Form error: " << e.what() << std::endl;
    }

    try {
        // This should throw an exception
        Form invalidForm("InvalidForm", 151, 151);
    } catch (const std::exception& e) {
        std::cout << "Error creating form: " << e.what() << std::endl;
    }

    return 0;
}