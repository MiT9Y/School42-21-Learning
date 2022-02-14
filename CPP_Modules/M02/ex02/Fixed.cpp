/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:25:24 by msimon            #+#    #+#             */
/*   Updated: 2022/01/19 12:53:54 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixed_value = 0;
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed::Fixed(const Fixed &val)
{
	*this = val;
	return ;
}

Fixed::Fixed(const int &ival)
{
	this->_fixed_value = ival << this->_fractional_bit;
}

Fixed::Fixed(const float &fval)
{
	this->_fixed_value = roundf(fval * (1 << this->_fractional_bit));
}

Fixed	&Fixed::operator=(const Fixed &val)
{
	if (this != &val)
		this->_fixed_value = val.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &val) const
{
	return (this->getRawBits() > val.getRawBits());
}

bool	Fixed::operator<(const Fixed &val) const
{
	return (this->getRawBits() < val.getRawBits());
}

bool	Fixed::operator>=(const Fixed &val) const
{
	return (this->getRawBits() >= val.getRawBits());
}

bool	Fixed::operator<=(const Fixed &val) const
{
	return (this->getRawBits() <= val.getRawBits());
}

bool	Fixed::operator==(const Fixed &val) const
{
	return (this->getRawBits() == val.getRawBits());
}

bool	Fixed::operator!=(const Fixed &val) const
{
	return (this->getRawBits() != val.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &val) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() + val.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(const Fixed &val) const
{
	Fixed	res;

	res.setRawBits(this->getRawBits() - val.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(const Fixed &val) const
{
	return (Fixed(this->toFloat() * val.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &val) const
{
	return (Fixed(this->toFloat() / val.toFloat()));
}

Fixed	&Fixed::operator++(void)
{
	this->_fixed_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	prev(*this);

	this->_fixed_value++;
	return (prev);
}

Fixed	&Fixed::operator--(void)
{
	this->_fixed_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	prev(*this);

	this->_fixed_value--;
	return (prev);
}

int	Fixed::toInt(void) const
{
	return (this->_fixed_value >> this->_fractional_bit);
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_value / (1 << this->_fractional_bit));
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed_value);
}

void	Fixed::setRawBits(int const val)
{
	this->_fixed_value = val;
	return ;
}

Fixed		&Fixed::min(Fixed &val1, Fixed &val2)
{
	if (val1 < val2)
		return (val1);
	else
		return (val2);
}

const Fixed	&Fixed::min(const Fixed &val1, const Fixed &val2)
{
	if (val1 < val2)
		return (val1);
	else
		return (val2);
}

Fixed		&Fixed::max(Fixed &val1, Fixed &val2)
{
	if (val1 < val2)
		return (val2);
	else
		return (val1);
}

const Fixed	&Fixed::max(const Fixed &val1, const Fixed &val2)
{
	if (val1 < val2)
		return (val2);
	else
		return (val1);
}

std::ostream	&operator<<(std::ostream &ostream, const Fixed &fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}
