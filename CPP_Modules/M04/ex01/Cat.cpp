/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:20:25 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 14:10:13 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default constructor (Cat Class)" << std::endl;
	_type = "Cat";
	_brain = new Brain;
	_brain->get_ideas()[0] = "EAT!";
	return ;
}

Cat::Cat(const Cat &obj)
{
	std::cout << "Copy constructor (Cat Class)" << std::endl;
	*this = obj;
	return ;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Destructor (Cat Class)" << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow";
	return ;	
}
