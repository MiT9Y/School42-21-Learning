/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 08:43:48 by msimon            #+#    #+#             */
/*   Updated: 2022/01/13 09:23:18 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon)
{
	_name = name;
}

void	HumanA::attack(void)
{
	std::cout
		<< _name
		<< " attacks with his "
		<< _weapon.getType()
		<< std::endl;
}
