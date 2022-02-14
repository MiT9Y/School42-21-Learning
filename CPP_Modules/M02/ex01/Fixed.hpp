/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:15:09 by msimon            #+#    #+#             */
/*   Updated: 2022/01/19 08:52:53 by msimon           ###   ########.fr       */
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

		int		toInt(void) const;
		float	toFloat(void) const;
		
		int		getRawBits(void) const;
		void	setRawBits(int const val);

	private:
		int					_fixed_value;
		static const int	_fractional_bit = 8;
};

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixed);

#endif