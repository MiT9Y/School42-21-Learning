/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:09:37 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 20:30:18 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Default constructor (Ice Class)" << std::endl;
	return ;
}

Ice::Ice(const Ice &obj): AMateria("ice")
{
	std::cout << "Copy constructor (Ice Class)" << std::endl;
	*this = obj;
	return ;
}

Ice::~Ice(void)
{
	std::cout << "Destructor (Ice Class)" << std::endl;
	return ;
}

Ice	&Ice::operator=(const Ice &obj)
{
	std::cout << "Assignement operator (Ice Class)" << std::endl;
	if (this != &obj)
		_type = obj.getType();
	return *this;
}

AMateria	*Ice::clone(void) const
{
	AMateria	*res = new Ice(*this);

	return (res);
}
void	Ice::use(ICharacter& target)
{
	std::cout
		<< "* shoots an ice bolt at "
		<< target.getName() << " *"
		<< std::endl;
	return ;
}
