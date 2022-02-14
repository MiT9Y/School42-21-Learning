/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:20:25 by msimon            #+#    #+#             */
/*   Updated: 2022/01/24 18:03:07 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << "Default constructor (Cat Class)" << std::endl;
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
	std::cout << "Destructor (Cat Class)" << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow";
	return ;	
}
