#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat highRanking("Alice", 1);
        std::cout << highRanking << std::endl;
        
        // This should throw an exception
        highRanking.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat lowRanking("Bob", 150);
        std::cout << lowRanking << std::endl;
        
        // This should throw an exception
        lowRanking.decrementGrade();
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        // This should throw an exception
        Bureaucrat invalidBureaucrat("Charlie", 151);
    } catch (const std::exception& e) {
        std::cout << "Error creating bureaucrat: " << e.what() << std::endl;
    }

    return 0;
}