/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:10:57 by msimon            #+#    #+#             */
/*   Updated: 2022/02/01 20:43:01 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FourTypes.hpp"

int	main(int argc, char **argv)
{
	FourTypes	*ft_val;
	if (argc != 2)
	{
		std::cerr << "Incorrect input data. Use './convert literal' form" << std::endl;
		return (1);
	}
	switch (FourTypes::getType(argv[1]))
	{
		case 0:
			ft_val = new FourTypes(FourTypes::getCharValue(argv[1]));
			break;
		case 1:
			ft_val = new FourTypes(FourTypes::getIntValue(argv[1]));
			break;
		case 2:
			ft_val = new FourTypes(FourTypes::getFloatValue(argv[1]));
			break;
		case 3:
			ft_val = new FourTypes(FourTypes::getDoubleValue(argv[1]));
			break;
		default:
			std::cerr << "Incorrect input data. Literal mast be: char, int, float or double" << std::endl;
			return (1);
	}
	ft_val->printChar();
	ft_val->printInt();
	ft_val->printFloat();
	ft_val->printDouble();
	delete ft_val;
	return (0);
}
