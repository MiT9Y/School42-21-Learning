/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:10:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/27 17:22:21 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	bob("BOB", 1);
		Bureaucrat	bob2(bob);
		Bureaucrat	mad("MAD", 150);

		std::cout << bob2 << std::endl;
		std::cout << mad << std::endl;
		mad = bob;
		std::cout << mad << std::endl;
		try
		{
			mad.downGrade(100);
		}
		catch (std::exception & e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		std::cout << mad << std::endl;
		mad.upGrade(9);
		std::cout << mad << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
