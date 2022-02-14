/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:43:11 by msimon            #+#    #+#             */
/*   Updated: 2022/01/22 13:20:42 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	std::cout
		<< "Create " << this->_name << "(ScavTrap object)"
		<< std::endl;
	_max_hitpoints = _hitpoints = 100;
	_energy = 50;
	_damage = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &obj): ClapTrap(obj.get_name())
{
	std::cout
		<< "Copy constructor called (ScavTrap object)"
		<< std::endl;
	*this = obj;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout
		<< "Delete " << this->_name << "(ScavTrap object)"
		<< std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!_hitpoints)
	{
		std::cout
			<< "ScavTrap " << _name << " is dead"
			<< std::endl;
		return ;
	}
	std::cout
		<< "ScavTrap " << _name
		<< " attack " << target
		<< ", causing " << _damage
		<< " points of damage!"
		<< std::endl;
	return ;
}

void	ScavTrap::guardGate(void)
{
	if (!_hitpoints)
	{
		std::cout
			<< "ScavTrap " << _name << " is dead"
			<< std::endl;
		return ;
	}
	std::cout
		<< "ScavTrap " << _name << " have enterred in Gate keeper mode."
		<< std::endl;
	return ;
}

std::ostream	&operator<<(std::ostream &ostream, const ScavTrap &obj)
{
	ostream << "ScavTrap " << obj.get_name()
		<< "(hitpoints:" << obj.get_hitpoints()
		<< ", energy:" << obj.get_energy()
		<< ", damage:" << obj.get_damage() << ")";
	return ostream;
}