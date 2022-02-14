/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 08:38:23 by msimon            #+#    #+#             */
/*   Updated: 2022/01/23 20:26:56 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout
		<< "Create " << this->_name << "(DiamondTrap object)"
		<< std::endl;
	_max_hitpoints = _hitpoints = 100;
	_energy = 50;
	_damage = 30;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj): ClapTrap(obj.get_name() + "_clap_name"), ScavTrap(obj.get_name()), FragTrap(obj.get_name())
{
	std::cout
		<< "Copy constructor called (DiamondTrap object)"
		<< std::endl;
	*this = obj;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout
		<< "Delete " << this->_name << "(DiamondTrap object)"
		<< std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout
		<< "Assignation operator called (DiamondTrap object)"
		<< std::endl;			
	if (this != &obj)
	{
		this->_name = obj.get_name();
		ScavTrap::_name = obj.get_name() + "_clap_name";
		this->_max_hitpoints = this->_hitpoints = obj.get_hitpoints();
		this->_energy = obj.get_energy();
		this->_damage = obj.get_damage();
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout
		<< "I am " << this->_name
		<< " and my ClapTrap name is "
		<< ClapTrap::_name << std::endl;
	return ;
}

const std::string	&DiamondTrap::get_name(void) const
{
	return (this->_name);
}

std::ostream	&operator<<(std::ostream &ostream, const DiamondTrap &obj)
{
	ostream << "DiamondTrap " << obj.DiamondTrap::get_name()
		<< "(hitpoints:" << obj.DiamondTrap::get_hitpoints()
		<< ", energy:" << obj.DiamondTrap::get_energy()
		<< ", damage:" << obj.DiamondTrap::get_damage() << ")";
	return ostream;
}
