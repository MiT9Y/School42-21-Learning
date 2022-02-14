/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:46:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/24 18:03:18 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << "Default constructor (Dog Class)" << std::endl;
	return ;
}

Dog::Dog(const Dog &obj)
{
	std::cout << "Copy constructor (Dog Class)" << std::endl;
	*this = obj;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Destructor (Dog Class)" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof";
	return ;	
}
