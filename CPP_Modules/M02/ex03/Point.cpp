/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:58:06 by msimon            #+#    #+#             */
/*   Updated: 2022/01/19 12:02:47 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(Fixed()), y(Fixed())
{
	return ;
}

Point::~Point(void)
{
	return ;
}

Point::Point(const Point &val): x(val.x), y(val.y)
{
	return ;
}

Point::Point(const float &val_x, const float &val_y): x(Fixed(val_x)), y(Fixed(val_y))
{
	return ;
}

Point	&Point::operator=(const Point &val)
{
	(void)val;
	return (*this);
}

Fixed	Point::getx(void) const
{
	return(this->x);
}

Fixed	Point::gety(void) const
{
	return(this->y);	
}
