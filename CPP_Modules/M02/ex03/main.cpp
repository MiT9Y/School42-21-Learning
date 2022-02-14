/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:54:25 by msimon            #+#    #+#             */
/*   Updated: 2022/01/19 14:38:00 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	std::cout << "Test 1. Point is inside." << std::endl;
	std::cout << "\tresult: " <<
		bsp(Point(10.0f, 10.0f)
		,Point(30.0f, 10.0f)
		,Point(20.0f, 40.0f)
		,Point(29.95f, 10.1f))
		<< std::endl << std::endl;

	std::cout << "Test 2. Point is outside." << std::endl;
	std::cout << "\tresult: " <<
		bsp(Point(30.0f, 10.0f)
		,Point(10.0f, 10.0f)
		,Point(20.0f, 40.0f)
		,Point(29.99f, 10.1f))
		<< std::endl << std::endl;

	std::cout << "Test 3. Point is on the edge." << std::endl;
	std::cout << "\tresult: " <<
		bsp(Point(20.0f, 10.0f)
		,Point(10.0f, 10.0f)
		,Point(10.0f, 30.0f)
		,Point(10.0f, 20.0f))
		<< std::endl << std::endl;

	std::cout << "Test 4. Triangle is line, point is on the edge." << std::endl;
	std::cout << "\tresult: " <<
		bsp(Point(20.0f, 10.0f)
		,Point(10.0f, 10.0f)
		,Point(30.0f, 10.0f)
		,Point(15.0f, 10.0f))
		<< std::endl << std::endl;

	std::cout << "Test 5. Triangle is point, point is on the vertex." << std::endl;
	std::cout << "\tresult: " <<
		bsp(Point(10.0f, 10.0f)
		,Point(10.0f, 10.0f)
		,Point(10.0f, 10.0f)
		,Point(10.0f, 10.0f))
		<< std::endl << std::endl;

	return (0);
}
