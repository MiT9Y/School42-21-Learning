/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:28:21 by msimon            #+#    #+#             */
/*   Updated: 2022/01/23 20:17:49 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	{
		std::cout << std::endl << "*** ClapTrap TEST ***" << std::endl;

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
	}
	{
		std::cout << std::endl << "*** ScavTrap TEST ***" << std::endl;

		ScavTrap	ted("TED");
		ScavTrap	ted2(ted);
		ScavTrap	ted3("No name");

		ted3 = ted;
		std::cout << ted << std::endl;
		std::cout << ted2 << std::endl;
		std::cout << ted3 << std::endl;
		ted.attack("BOB");
		ted.guardGate();
		ted.takeDamage(2);
		std::cout << ted << std::endl;
		ted.beRepaired(10);
		ted.takeDamage(200);
		ted.attack("BOB");
		ted.guardGate();
	}
	{
		std::cout << std::endl << "*** FragTrap TEST ***" << std::endl;

		FragTrap	roy("ROY");
		FragTrap	roy2(roy);
		FragTrap	roy3("No name");

		roy3 = roy;
		std::cout << roy << std::endl;
		std::cout << roy2 << std::endl;
		std::cout << roy3 << std::endl;
		roy.highFivesGuys();
		roy.takeDamage(2);
		std::cout << roy << std::endl;
		roy.beRepaired(10);
		roy.takeDamage(200);
		roy.highFivesGuys();
	}
	{
		std::cout << std::endl << "*** DiamondTrap TEST ***" << std::endl;

		DiamondTrap	big("BIG");
		DiamondTrap	big2(big);
		DiamondTrap	big3("No name");

		big3 = big;
		std::cout << big << std::endl;
		std::cout << big2 << std::endl;
		std::cout << big3 << std::endl;
		big.attack("ME");
		big3.attack("ME");
		big.whoAmI();
	}

	return (0);
}