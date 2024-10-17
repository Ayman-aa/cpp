#include "header.hpp"

int main()
{
    int intArr[] = {1, 2, 3, 4, 5};
    iter(intArr, 5, print<int>);
    std::cout << std::endl;

    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(doubleArr, 5, print<double>);
    std::cout << std::endl;

    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    iter(charArr, 5, print<char>);
    std::cout << std::endl;

    return 0;
}