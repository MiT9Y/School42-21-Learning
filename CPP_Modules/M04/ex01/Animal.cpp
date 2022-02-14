/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:04:20 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 14:35:14 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	_type = "Animal";
	_brain = NULL;
	std::cout << "Default constructor (Animal Class)" << std::endl;
	return ;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Copy constructor (Animal Class)" << std::endl;
	*this = obj;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Destructor (Animal Class)" << std::endl;
	return ;
}

Animal	&Animal::operator=(const Animal &obj)
{
	std::cout << "Assignement operator (Animal Class)" << std::endl;
	if (this != &obj)
	{
		this->_type = obj.getType();
		if (obj.get_brain() && _brain)
		{
			int	i = -1;
			while (++i < Brain::n_ideas)
				_brain->get_ideas()[i] = obj.get_brain()->get_idea(i);
		}
	}
	return *this;
}

void	Animal::makeSound(void) const
{
	std::cout << "No specific sound";
	return ;
}

const std::string	&Animal::getType(void) const
{
	return (this->_type);
}

Brain	*Animal::get_brain(void) const
{
	return (_brain);
}

std::ostream	&operator<<(std::ostream &ostream, const Animal &obj)
{
	ostream << "This is " << obj.getType() << " and hi say: ";
	obj.makeSound();
	return ostream;
}
