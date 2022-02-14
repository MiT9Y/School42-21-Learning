/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:10:57 by msimon            #+#    #+#             */
/*   Updated: 2022/02/02 15:02:31 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TestType.hpp"

uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int	main(void)
{
	Data		d1;
	Data*		d2;
	uintptr_t	ptr;

	d1.x = 9;
	d1.y = 99;

	std::cout << &d1 << std::endl;
	std::cout << "d1.x: " << d1.x << std::endl;
	std::cout << "d1.y: " << d1.y << std::endl;
	ptr  = serialize(&d1);
	std::cout << std::hex << ptr << std::dec << std::endl;
	d2  = deserialize(ptr);
	std::cout << d2 << std::endl;
	d2->x *= 2;
	d2->y *= 2;
	std::cout << "d1.x: " << d1.x << std::endl;
	std::cout << "d1.y: " << d1.y << std::endl;
	return (0);
}
