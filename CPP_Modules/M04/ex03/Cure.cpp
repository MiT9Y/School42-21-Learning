/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:50:17 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 20:56:49 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Default constructor (Cure Class)" << std::endl;
	return ;
}

Cure::Cure(const Cure &obj): AMateria("cure")
{
	std::cout << "Copy constructor (Cure Class)" << std::endl;
	*this = obj;
	return ;
}

Cure::~Cure(void)
{
	std::cout << "Destructor (Cure Class)" << std::endl;
	return ;
}

Cure &Cure::operator=(const Cure &obj)
{
	std::cout << "Assignement operator (Cure Class)" << std::endl;
	if (this != &obj)
		_type = obj.getType();
	return *this;
}

AMateria	*Cure::clone(void) const
{
	AMateria	*res = new Cure(*this);

	return (res);
}
void	Cure::use(ICharacter& target)
{
	std::cout
		<< "* heals " << target.getName() << "’s wounds *"
		<< std::endl;
	return ;
}
