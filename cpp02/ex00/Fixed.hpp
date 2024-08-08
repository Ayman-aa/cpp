#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		/* Constructors & Destructor */
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);
		
		/* Getter & Setter */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/* Copy assignment operator */
		Fixed	&operator=(const Fixed &rhs);

};
#endif