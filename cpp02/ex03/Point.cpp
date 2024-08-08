#include "Point.hpp"

/* Constructors & Destructors */
Point::Point(void) : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point::~Point(void) {}

/* Getters */
const Fixed	&Point::getX(void) const { return (this->_x); }

const Fixed	&Point::getY(void) const { return (this->_y); }

// Assignment operator overload
Point &Point::operator=(const Point& other) {
    if (this != &other)
    {
        ((Fixed) this->_x) = other.getX();
         ((Fixed) this->_y) = other.getY();
    }
    return *this;
}
