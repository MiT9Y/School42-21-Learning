/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:15:09 by msimon            #+#    #+#             */
/*   Updated: 2022/01/19 08:52:24 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &val);
		Fixed(const int &ival);
		Fixed(const float &fval);

		Fixed	&operator=(const Fixed &val);
		bool	operator>(const Fixed &val) const;
		bool	operator<(const Fixed &val) const;
		bool	operator>=(const Fixed &val) const;
		bool	operator<=(const Fixed &val) const;
		bool	operator==(const Fixed &val) const;
		bool	operator!=(const Fixed &val) const;
		Fixed	operator+(const Fixed &val) const;
		Fixed	operator-(const Fixed &val) const;
		Fixed	operator*(const Fixed &val) const;
		Fixed	operator/(const Fixed &val) const;
		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		int		toInt(void) const;
		float	toFloat(void) const;
		
		int		getRawBits(void) const;
		void	setRawBits(int const val);

		static Fixed		&min(Fixed &val1, Fixed &val2);
		static const Fixed	&min(const Fixed &val1, const Fixed &val2);
		static Fixed		&max(Fixed &val2, Fixed &val1);
		static const Fixed	&max(const Fixed &val1, const Fixed &val2);

	private:
		int					_fixed_value;
		static const int	_fractional_bit = 8;
};

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixed);

#endif