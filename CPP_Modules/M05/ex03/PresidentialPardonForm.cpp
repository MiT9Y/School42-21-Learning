/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:49:58 by msimon            #+#    #+#             */
/*   Updated: 2022/01/29 06:15:01 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

bool	PresidentialPardonForm::messege_visible = true;

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): Form("presidential pardon", 25, 5), _target(target)
{
	if (PresidentialPardonForm::messege_visible)
		std::cout << "Default constructor (PresidentialPardonForm Class)" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj): Form("presidential pardon", 25, 5), _target(obj.getTarget())
{
	*this = obj;
	if (PresidentialPardonForm::messege_visible)
		std::cout << "Copy constructor (PresidentialPardonForm Class)" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (PresidentialPardonForm::messege_visible)
		std::cout << "Destructor (PresidentialPardonForm Class)" << std::endl;
	return ;
}
		
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	(void)obj;
	if (PresidentialPardonForm::messege_visible)
		std::cout << "Assignement operator (PresidentialPardonForm Class)" << std::endl;
	return *this;
}

const std::string	&PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw Form::noSignedForm;
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Form::GradeTooLowException;
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}
