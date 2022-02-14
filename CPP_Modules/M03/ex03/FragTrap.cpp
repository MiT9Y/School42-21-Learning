/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:15:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/23 17:39:42 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	std::cout
		<< "Create " << this->_name << "(FragTrap object)"
		<< std::endl;
	_max_hitpoints = _hitpoints = 100;
	_energy = 100;
	_damage = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &obj): ClapTrap(obj.get_name())
{
	std::cout
		<< "Copy constructor called (FragTrap object)"
		<< std::endl;
	*this = obj;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout
		<< "Delete " << this->_name << "(FragTrap object)"
		<< std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void)
{
	if (!_hitpoints)
	{
		std::cout
			<< "FragTrap " << _name << " is dead"
			<< std::endl;
		return ;
	}
	std::cout
		<< "High fives (FragTrap object)"
		<< std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &ostream, const FragTrap &obj)
{
	ostream << "FragTrap " << obj.get_name()
		<< "(hitpoints:" << obj.get_hitpoints()
		<< ", energy:" << obj.get_energy()
		<< ", damage:" << obj.get_damage() << ")";
	return ostream;
}
