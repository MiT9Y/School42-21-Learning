/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:19:17 by msimon            #+#    #+#             */
/*   Updated: 2022/02/05 18:12:57 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <set>
#include <stdexcept>
#include "easyfind.hpp"

int	main(void)
{
	int					i = -1;
	std::vector <int>	vect;

	while (++i < 10)
		vect.push_back(i);

	try
	{
		std::cout << *(easyfind(vect, 4)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << *(easyfind(vect, 11)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::set <int> myset;

	myset.insert(100);
	myset.insert(200);
	try
	{
		std::cout << *(easyfind(myset, 200)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << *(easyfind(myset, 300)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
