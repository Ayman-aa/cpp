#include "Fixed.hpp"
# include <iomanip>

int main( void )
{
    Fixed a(5);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    //totaly optional but ensures the visibility of float conversion
    std::cout << std::fixed << std::setprecision(1);
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}