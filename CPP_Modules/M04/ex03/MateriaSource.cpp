/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:42:11 by msimon            #+#    #+#             */
/*   Updated: 2022/01/26 15:57:09 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	int	i = -1;
	
	_learn_index = 0;
	while (++i < MateriaSource::arr_size)
		_materias[i] = NULL;
	std::cout << "Default constructor (MateriaSource Class)" << std::endl;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &obj)
{
	int	i = -1;

	_learn_index = 0;
	while (++i < MateriaSource::arr_size)
		_materias[i] = NULL;
	std::cout << "Copy constructor (MateriaSource Class)" << std::endl;
	*this = obj;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	int	i = -1;

	while (++i < MateriaSource::arr_size)
		if (_materias[i])
			delete _materias[i];
	std::cout << "Destructor (MateriaSource Class)" << std::endl;
	return ;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &obj)
{
	int	i = -1;

	_learn_index = 0;
	while (++i < MateriaSource::arr_size)
	{
		if (_materias[i])
			delete _materias[i];
		if (obj._materias[i])
		{
			_learn_index = i + 1;
			_materias[i] = obj._materias[i]->clone();
		}
		else
			_materias[i] = NULL;
	}
	std::cout << "Assignement operator (MateriaSource Class)" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (_learn_index == MateriaSource::arr_size)
	{
		std::cout << "Array is full" << std::endl;
		delete materia;
	}
	else
	{
		_materias[_learn_index] = materia;
		std::cout
			<< "Materia " << materia->getType()
			<< " learn in slot - " << _learn_index
			<< std::endl;
		_learn_index++;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i = -1;

	while (++i < MateriaSource::arr_size)
		if (_materias[i]->getType() == type)
			return _materias[i]->clone();
	return (NULL);
}
