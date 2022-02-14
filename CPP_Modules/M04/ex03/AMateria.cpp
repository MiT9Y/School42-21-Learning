/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:40:08 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 20:07:29 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type)
{
	std::cout << "Default constructor (AMateria Class)" << std::endl;
	_type = type;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << "Destructor (AMateria Class)" << std::endl;
	return ;
}

const std::string	&AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	(void) target;
	return ;
}
