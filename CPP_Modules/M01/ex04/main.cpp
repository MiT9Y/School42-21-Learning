/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:02:47 by msimon            #+#    #+#             */
/*   Updated: 2022/01/14 15:10:34 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "File.hpp"

std::string	to_up(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	return (str);
}

int	main(int argc, char **argv)
{
	File	file;

	if (argc < 4)
	{
		std::cerr << "ERROR: input parameters must be more than two\n";
		return (1);
	}
	else
	{
		if (!file.open_and_read(argv[1]))
			return(1);
		if (!file.replace(argv[2], argv[3]))
			return(1);
		if (!file.write_and_reset(to_up(argv[1]) + ".replace"))
			return (1);
	}
	std::cout << "SUCCESS" <<std::endl;
	return (0);
}
