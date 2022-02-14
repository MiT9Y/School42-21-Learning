/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:29:31 by msimon            #+#    #+#             */
/*   Updated: 2022/01/12 12:50:28 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N > 0)
	{
		Zombie*	zombies;
		int	i = -1;

		zombies = new Zombie[N];
		while (++i < N)
			zombies[i].set_name(name + std::to_string(i));
		return(zombies);
	}
	else
		return (NULL);
}
