/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:13:27 by msimon            #+#    #+#             */
/*   Updated: 2022/02/06 07:14:39 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <limits>
#include <vector>
#include "Span.hpp"

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try {sp.addNumber(-1);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	
	std::cout << std::endl << " *** " << std::endl;
	unsigned int				maxSize = 100000;
	int							i;
	Span 						my_sp = Span(maxSize);
	std::vector <int>			vect;
	std::vector <int>::iterator	itEnd;

	try {my_sp.longestSpan();}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	srand(time(NULL));
	i = -1;
	while (++i < static_cast <int>(maxSize) / 2)
		my_sp.addNumber(rand());
	std::cout << my_sp.shortestSpan() << std::endl;
	std::cout << my_sp.longestSpan() << std::endl;
	i = -1;
	while (++i < (static_cast <int>(maxSize) / 2) + 10)
	{
		if (i == static_cast <int>(maxSize) / 3)
			itEnd = (vect.end() - 1);
		vect.push_back(-i);
	}
	try {my_sp.addItRange(vect.begin(), vect.end());}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	my_sp.addItRange(vect.begin(), itEnd);
	std::cout << my_sp.shortestSpan() << std::endl;
	std::cout << my_sp.longestSpan() << std::endl;
	my_sp.addNumber(std::numeric_limits<int>::min());
	my_sp.addNumber(std::numeric_limits<int>::min());
	my_sp.addNumber(std::numeric_limits<int>::max());
	std::cout << my_sp.shortestSpan() << std::endl;
	std::cout << my_sp.longestSpan() << std::endl;
	
	return (0);
}
