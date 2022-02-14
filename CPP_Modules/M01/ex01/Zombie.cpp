/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 08:51:11 by msimon            #+#    #+#             */
/*   Updated: 2022/01/12 12:39:48 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string val)
{
	set_name(val);
}

Zombie::~Zombie(void)
{
	std::cout
		<< "zombie "
		<< get_name()
		<< " is deleted"
		<< std::endl;
}

void	Zombie::set_name(std::string val)
{
	_name = val;
}

std::string	Zombie::get_name(void) const
{
	return (_name);
}

void	Zombie::announce(void) const
{
	std::cout
		<< "<" << get_name() << "> "
		<< "BraiiiiiiinnnzzzZ..."
		<< std::endl;
}
