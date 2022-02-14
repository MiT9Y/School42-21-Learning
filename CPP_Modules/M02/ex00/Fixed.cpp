/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:25:24 by msimon            #+#    #+#             */
/*   Updated: 2022/01/19 09:05:23 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout
		<< "Default constructor called"
		<< std::endl;
	this->_fixed_value = 0;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout
		<< "Destructor called"
		<< std::endl;
	return ;
}

Fixed::Fixed(const Fixed &val)
{
	std::cout
		<< "Copy constructor called"
		<< std::endl;
	*this = val;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &val)
{
	std::cout
		<< "Assignation operator called"
		<< std::endl;
	if (this != &val)
		this->_fixed_value = val.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout
		<< "getRawBits member function called"
		<< std::endl;
	return (this->_fixed_value);
}

void	Fixed::setRawBits(int const val)
{
 	std::cout
		<< "setRawBits member function called"
		<< std::endl;
	this->_fixed_value = val;
	return ;
}
