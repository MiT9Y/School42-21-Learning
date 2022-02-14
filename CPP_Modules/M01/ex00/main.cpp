/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:10:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/12 12:47:54 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	std::cout << std::endl << "*** TEST ZOMBIE Z0 ***" << std::endl;
	Zombie	z0;
	z0.announce();

	{
		std::cout << std::endl << "*** TEST ZOMBIE Z1 ***" << std::endl;
		Zombie	z1("Z1");
		z1.announce();
	}

	std::cout << std::endl << std::endl << "*** TEST ZOMBIE Z2 ***" << std::endl;
	Zombie*	z2;
	z2 = newZombie("Z2");
	z2->announce();

	std::cout << std::endl << "*** TEST ZOMBIE Z3 ***" << std::endl;
	randomChump("Z3");
	
	delete z2;

	return (0);
}
