#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

//converting an int value to a  fixed-point value by shifting the int value by 8 bits or n*2^8
Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

//converting an float-point to fixed-point value by multiplying n*256 then using roundof to get the (Excessive/negligent) value
Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}
// we divide the fixed-point value by 256 to get the float value
float Fixed::toFloat(void) const
{
    return (float)this->_fixedPointValue / (1 << _fractionalBits);
}
// we shift the fixed-point value by 8 bits to get the int value, we devide the fixed-point value by 256/2^8
int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

// call an object "out" of type ostream and pass the object "fixed" of type Fixed then return the object "out" with the value of the object "fixed" in float
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}