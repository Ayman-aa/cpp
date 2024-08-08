#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{

	private:
		const Fixed	_x;
		const Fixed	_y;

	public:
		/* Constructors & Destructors */
		Point(void);
		Point(const float x, const float y);
		Point(const Point &point);
		~Point(void);

		/* Getters */
		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;

		/* Overloaded operator */
		Point& operator=(const Point& other);
};

#endif
