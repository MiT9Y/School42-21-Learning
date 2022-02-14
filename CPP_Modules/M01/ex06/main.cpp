/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:02:50 by msimon            #+#    #+#             */
/*   Updated: 2022/01/16 11:51:58 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

int	main(int argc, char **argv)
{
	Karen karen;

	if (argc > 1)
	{
		karen.set_allow_level(argv[1]);
		karen.complain("DEBUG");
		karen.complain("INFO");
		karen.complain("WARNING");
		karen.complain("ERROR");
		karen.complain("OTHER");
	}
	else
		std::cout
			<< "Error: you must specify the input parameters"
			<< std::endl;
	return (0);
}