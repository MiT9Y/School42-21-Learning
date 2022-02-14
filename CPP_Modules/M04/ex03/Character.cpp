/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:37:16 by msimon            #+#    #+#             */
/*   Updated: 2022/01/26 15:35:33 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name)
{
	int	i = -1;
	
	_name = name;
	_unequip_arr_index = 0;
	while (++i < Character::arr_size)
		_materias[i] = NULL;
	std::cout << "Default constructor (Character Class)" << std::endl;
	return ;
}

Character::Character(Character const &obj) 
{
	int	i = -1;

	_unequip_arr_index = 0;
	while (++i < Character::arr_size)
		_materias[i] = NULL;	
	std::cout << "Copy constructor (Character Class)" << std::endl;
	*this = obj;
	return ;
}

Character::~Character(void)
{
	int	i;

	i = -1;
	while (++i < Character::arr_size)
		if (_materias[i])
			delete _materias[i];
	i = -1;
	while (++i < _unequip_arr_index)
		delete _unequip_arr[i];
	std::cout << "Destructor (Character Class)" << std::endl;
	return ;
}

Character	&Character::operator=(Character const &obj)
{
	int	i;

	if (this != &obj)
	{
		_name = obj.getName();
		i = -1;
		while (++i < Character::arr_size)
		{
			if (_materias[i])
				delete _materias[i];
			if (obj._materias[i])
				_materias[i] = obj._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
		i = -1;
		while (++i < _unequip_arr_index)
			delete _unequip_arr[i];
		i = -1;
		_unequip_arr_index = obj._unequip_arr_index;
		while (++i < _unequip_arr_index)
			_unequip_arr[i] = obj._unequip_arr[i]->clone();
	}
	std::cout << "Assignement operator (Character Class)" << std::endl;
	return (*this);
}

std::string const	&Character::getName() const
{
	return(_name);
}

void	Character::equip(AMateria* m)
{
	int	i = -1;

	while (++i < Character::arr_size)
	{
		if (!_materias[i])
		{
			std::cout
				<< "Equipped a " << m->getType()
				<< " in slot - " << i << std::endl;
			_materias[i] = m;
			return ;
		}
	}
	std::cout
		<< "Not Equipped. Array is full."
		<< std::endl;
	delete m;
	return ;
}

void	Character::unequip(int idx)
{
	if (idx < 0 && idx >= Character::arr_size)
	{
		std::cout << "Error index" << std::endl;
		return ;
	}
	if (_unequip_arr_size == _unequip_arr_index)
	{
		std::cout << "Unequip buffer is full" << std::endl;
		return ;
	}
	if (_materias[idx])
	{
		_unequip_arr[_unequip_arr_index++] = _materias[idx];
		_materias[idx] = NULL;
	}
	std::cout << "Unequipped" << std::endl;
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 && idx >= Character::arr_size)
	{
		std::cout << "Error index" << std::endl;
		return ;
	}
	if (_unequip_arr_size == _unequip_arr_index)
	{
		std::cout << "Unequip buffer is full" << std::endl;
		return ;
	}
	if (_materias[idx])
	{
		_materias[idx]->use(target);
		unequip(idx);
	}
}
