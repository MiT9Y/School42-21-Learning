/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:34:29 by msimon            #+#    #+#             */
/*   Updated: 2022/02/03 10:50:17 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template<typename T>
void	ft_print_el(T &val)
{
	std::cout << val << std::endl;
	return ;
}

template<typename T>
void	ft_sqrt(T &val)
{
	val = val * val;
	return ;
}

int	main(void)
{
	std::string	arr[3];

	arr[0] = "STR 1";
	arr[1] = "STR 2";
	arr[2] = "STR 3";
	iter(arr, 3, &ft_print_el);

	int	arr2[4];
	arr2[0] = 1;
	arr2[1] = 2;
	arr2[2] = 3;
	arr2[3] = 4;
	iter(arr2, 4, &ft_print_el);
	iter(arr2, 4, &ft_sqrt);
	iter(arr2, 4, &ft_print_el);
	return (0);
}