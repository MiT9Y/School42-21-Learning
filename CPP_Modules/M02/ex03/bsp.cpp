/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:00:31 by msimon            #+#    #+#             */
/*   Updated: 2022/01/19 14:36:53 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	v12;
	Fixed	v23;
	Fixed	v31;

	v12 = (a.getx() - point.getx()) * (b.gety() - a.gety())
		- (b.getx() - a.getx()) * (a.gety() - point.gety());
	v23 = (b.getx() - point.getx()) * (c.gety() - b.gety())
		- (c.getx() - b.getx()) * (b.gety() - point.gety());
	v31 = (c.getx() - point.getx()) * (a.gety() - c.gety())
		- (a.getx() - c.getx()) * (c.gety() - point.gety());
	if ((v12 > 0 && v23 > 0 && v31 >0)
		|| (v12 < 0 && v23 < 0 && v31 <0))
		return (true);
	else
		return (false);
}
