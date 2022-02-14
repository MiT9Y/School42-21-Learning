/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:04:20 by msimon            #+#    #+#             */
/*   Updated: 2022/01/24 18:03:40 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	_type = "Animal";
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
		this->_type = obj.getType();
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

std::ostream	&operator<<(std::ostream &ostream, const Animal &obj)
{
	ostream << "This is " << obj.getType() << " and hi say: ";
	obj.makeSound();
	return ostream;
}
