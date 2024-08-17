# include "Fixed.hpp"
# include <iomanip>

int main( void )
{
    Fixed a;
    Fixed const b(105);
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );
    
    //totaly optional but ensures the visibility of float conversion
    //std::cout << std::fixed << std::setprecision(4);


    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;


    return 0;
}