/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:46:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 14:10:09 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default constructor (Dog Class)" << std::endl;
	_type = "Dog";
	_brain = new Brain;
	_brain->get_ideas()[0] = "RUN!";
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
	delete _brain;
	std::cout << "Destructor (Dog Class)" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof";
	return ;	
}
