#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("bureaucrat", 2);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}