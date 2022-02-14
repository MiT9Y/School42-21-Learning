/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:58:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/24 18:03:48 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	_type = "WrongAnimal";
	std::cout << "Default constructor (WrongAnimal Class)" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "Copy constructor (WrongAnimal Class)" << std::endl;
	*this = obj;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor (WrongAnimal Class)" << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "Assignement operator (WrongAnimal Class)" << std::endl;
	if (this != &obj)
		this->_type = obj.getType();
	return *this;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "No specific sound";
	return ;
}

const std::string	&WrongAnimal::getType(void) const
{
	return (this->_type);
}

std::ostream	&operator<<(std::ostream &ostream, const WrongAnimal &obj)
{
	ostream << "This is " << obj.getType() << " and hi say: ";
	obj.makeSound();
	return ostream;
}
