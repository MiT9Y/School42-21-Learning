/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:25:05 by msimon            #+#    #+#             */
/*   Updated: 2022/01/22 13:04:23 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name):_name(name)
{
	_hitpoints = _max_hitpoints = 10;
	_energy = 10;
	_damage = 0;
	std::cout
		<< "Create " << _name << "(ClapTrap object)"
		<< std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout
		<< "Copy constructor called (ClapTrap object)"
		<< std::endl;
	*this = obj;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout
		<< "Delete " << _name << "(ClapTrap object)"
		<< std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout
		<< "Assignation operator called (ClapTrap object)"
		<< std::endl;			
	if (this != &obj)
	{
		_name = obj._name;
		_max_hitpoints = _hitpoints = obj._hitpoints;
		_energy = obj._energy;
		_damage = obj._damage;
	}
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	if (!_hitpoints)
	{
		std::cout
			<< "ClapTrap " << _name << " is dead"
			<< std::endl;
		return ;
	}
	std::cout
		<< "ClapTrap " << _name
		<< " attack " << target
		<< ", causing " << _damage
		<< " points of damage!"
		<< std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitpoints)
	{
		std::cout
			<< "ClapTrap " << _name << " is dead"
			<< std::endl;
		return ;
	}
	std::cout
		<< "ClapTrap " << _name
		<< " take damage ";
	if (_hitpoints < amount)
	{
		std::cout << _hitpoints;
		_hitpoints = 0;
	}
	else
	{
		_hitpoints -= amount;
		std::cout << amount;
	}
	std::cout << " and ";
	if (_hitpoints)
		std::cout
			<< _name <<" health is " << _hitpoints
			<< std::endl;
	else
		std::cout
			<< _name <<" is dead"
			<< std::endl;		
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitpoints)
	{
		std::cout
			<< "ClapTrap " << _name << " is dead"
			<< std::endl;
		return ;
	}
	if (_hitpoints == _max_hitpoints)
	{
		std::cout
			<< "ClapTrap " << _name << " has max hitpoints (" << _hitpoints << ")"
			<< std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " be repaired ";
	_hitpoints += amount;
	if (_max_hitpoints < _hitpoints)
	{
		std::cout << (amount + _max_hitpoints - _hitpoints);
		_hitpoints = _max_hitpoints;
	}
	else
		std::cout << amount;
	std::cout
		<< " hitpoints. " << _name << " has " << _hitpoints << " hitpoints."
		<< std::endl;
	return ;
}

const std::string	&ClapTrap::get_name(void) const
{
	return (this->_name);
}

const unsigned int	&ClapTrap::get_hitpoints(void) const
{
	return (this->_hitpoints);
}

const unsigned int	&ClapTrap::get_energy(void) const
{
	return (this->_energy);
}

const unsigned int	&ClapTrap::get_damage(void) const
{
	return (this->_damage);
}

std::ostream	&operator<<(std::ostream &ostream, const ClapTrap &obj)
{
	ostream << "ClapTrap " << obj.get_name()
		<< "(hitpoints:" << obj.get_hitpoints()
		<< ", energy:" << obj.get_energy()
		<< ", damage:" << obj.get_damage() << ")";
	return ostream;
}
