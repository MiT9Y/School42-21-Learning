/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:10:03 by msimon            #+#    #+#             */
/*   Updated: 2022/01/06 08:37:22 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char *get_up_str(char *str)
{
	char	*res;

    res = str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str += 1;
	}
	return (res);
}

int main(int argc, char **argv)
{
	int i;

	if (argc > 1)
	{
		i = 0;
		while (argv[++i])
			std::cout << get_up_str(argv[i]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
