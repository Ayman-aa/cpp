#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        Fixed(); // Default constructor
        Fixed(const int n); // Constructor with int parameter
        Fixed(const float n); // Constructor with float parameter
        Fixed(const Fixed &src); // Copy constructor
        Fixed &operator=(const Fixed &rhs); // Copy assignment operator
        ~Fixed(); // Destructor

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        // Comparison operators
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        // Arithmetic operators
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        // Increment/decrement operators
        Fixed &operator++(); // Pre-increment
        Fixed operator++(int); // Post-increment
        Fixed &operator--(); // Pre-decrement
        Fixed operator--(int); // Post-decrement

        // Static member functions
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

    std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
