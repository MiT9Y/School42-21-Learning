/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:28:21 by msimon            #+#    #+#             */
/*   Updated: 2022/01/20 16:42:55 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob("BOB");
	ClapTrap	bob2(bob);
	ClapTrap	bob3("No name");
	ClapTrap	*jim;

	bob3 = bob;

	std::cout << bob << std::endl;
	std::cout << bob2 << std::endl;
	std::cout << bob3 << std::endl;

	jim = new ClapTrap("JIM");
	jim->attack("BOB");
	jim->beRepaired(2);
	jim->takeDamage(3);
	jim->beRepaired(2);
	jim->beRepaired(4);
	jim->takeDamage(1);
	jim->takeDamage(11);
	jim->beRepaired(0);
	jim->attack("BOB");
	delete jim;
	return (0);
}