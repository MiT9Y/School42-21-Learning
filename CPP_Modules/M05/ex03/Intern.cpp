/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:58:50 by msimon            #+#    #+#             */
/*   Updated: 2022/01/29 08:01:34 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::runtime_error	Intern::errorFormName("Invalid form name");
bool	Intern::messege_visible = true;

Intern::Intern(void)
{
	_arr_functions[0] = &Intern::_getPresidentialPardonForm;
	_arr_functions[1] = &Intern::_getRobotomyRequestForm;
	_arr_functions[2] = &Intern::_getShrubberyCreationForm;
	if (Intern::messege_visible)
		std::cout << "Default constructor (Intern Class)" << std::endl;
	return ;
}

Intern::Intern(const Intern &obj)
{
	if (Intern::messege_visible)
		std::cout << "Copy constructor (Intern Class)" << std::endl;
	*this = obj;
	return ;
}

Intern::~Intern(void)
{
	if (Intern::messege_visible)
		std::cout << "Destructor (Intern Class)" << std::endl;
	return ;
}

Intern	&Intern::operator=(const Intern &obj)
{
	int		i = -1;

	if (Intern::messege_visible)
		std::cout << "Assignement operator (Intern Class)" << std::endl;
	if (this != &obj)
	{
		while (++i < MESSEGES_ARR_LEN)
		_arr_functions[i] = obj._arr_functions[i];
	}
	return *this;
}

Form	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	Form	*res;
	int		i = -1;

	if (target.empty())
		throw errorFormName;
	while (++i < MESSEGES_ARR_LEN)
	{
		res = (this->*_arr_functions[i])(target);
		if (res->getName() == formName)
		{
			std::cout << "Intern creates " << res->getName() << " form" << std::endl;
			return (res);
		}
		else
			delete res;
	}
	throw errorFormName;
	return (NULL);
}

Form*	Intern::_getPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Form*	Intern::_getRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form*	Intern::_getShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}
