/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:15:09 by msimon            #+#    #+#             */
/*   Updated: 2022/01/19 08:53:01 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &val);
		Fixed				&operator=(const Fixed &val);
		int					getRawBits(void) const;
		void				setRawBits(int const val);

	private:
		int					_fixed_value;
		static const int	_fractional_bit = 8;
};

#endif