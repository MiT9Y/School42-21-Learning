/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:10:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/12 12:53:26 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int		count = 10;
	int		i;
	Zombie*	zombies;

	zombies = zombieHorde(count, "Zzz");
	
	i = count;
	while (--i > -1)
		zombies[i].announce();

	delete [] zombies;
	return (0);
}
