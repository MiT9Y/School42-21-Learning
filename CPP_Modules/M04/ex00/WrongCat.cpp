/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:01:59 by msimon            #+#    #+#             */
/*   Updated: 2022/01/24 18:07:06 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "Default constructor (WrongCat Class)" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &obj)
{
	std::cout << "Copy constructor (WrongCat Class)" << std::endl;
	*this = obj;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor (WrongCat Class)" << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow";
	return ;	
}
