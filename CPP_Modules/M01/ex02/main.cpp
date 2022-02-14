/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:27:27 by msimon            #+#    #+#             */
/*   Updated: 2022/01/12 15:08:19 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		str;
	std::string*	stringPTR;
	std::string&	stringREF = str;

	stringPTR = &str;
	str = "HI THIS IS BRAIN";

	std::cout << std::endl;
	std::cout << "POINTER String:		" << &str << std::endl;
	std::cout << "POINTER StringPTR:	" << stringPTR << std::endl;
	std::cout << "POINTER StringREF:	" << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "VALUE String:		" << str << std::endl;
	std::cout << "VALUE StringPTR:	" << *stringPTR << std::endl;
	std::cout << "VALUE StringREF:	" << stringREF << std::endl;
	std::cout << std::endl;

	return (0);
}
