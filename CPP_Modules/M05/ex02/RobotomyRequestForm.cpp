/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:59:48 by msimon            #+#    #+#             */
/*   Updated: 2022/01/29 06:15:10 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool	RobotomyRequestForm::messege_visible = true;

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): Form("robotomy request", 72, 45), _target(target)
{
	if (RobotomyRequestForm::messege_visible)
		std::cout << "Default constructor (RobotomyRequestForm Class)" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj): Form("robotomy request", 72, 45), _target(obj.getTarget())
{
	*this = obj;
	if (RobotomyRequestForm::messege_visible)
		std::cout << "Copy constructor (RobotomyRequestForm Class)" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (RobotomyRequestForm::messege_visible)
		std::cout << "Destructor (RobotomyRequestForm Class)" << std::endl;
	return ;
}
		
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	(void)obj;
	if (RobotomyRequestForm::messege_visible)
		std::cout << "Assignement operator (RobotomyRequestForm Class)" << std::endl;
	return *this;
}

const std::string	&RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw Form::noSignedForm;
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Form::GradeTooLowException;
	else
	{
		std::srand(std::time(NULL));
		std::cout << "Makes some drilling noises... ";
		if (std::rand() % 2)
			std::cout << _target << " has been robotomized." << std::endl;
		else
			std::cout << _target << " the robotomy failed." << std::endl;
	}
	return ;
}
