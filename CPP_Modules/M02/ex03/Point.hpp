/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 08:40:06 by msimon            #+#    #+#             */
/*   Updated: 2022/01/19 12:02:12 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		~Point(void);
		Point(const Point &val);
		Point(const float &val_x, const float &val_y);
		Point	&operator=(const Point &val);
		Fixed	getx(void) const;
		Fixed 	gety(void) const;

	private:
		Fixed const	x;
		Fixed const	y;
};

#endif