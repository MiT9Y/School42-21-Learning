/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:46:21 by msimon            #+#    #+#             */
/*   Updated: 2022/01/27 23:22:02 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const std::range_error	Form::GradeTooHighException("Grade too high exception (FORM)");
const std::range_error	Form::GradeTooLowException("Grade too low exception (FORM)");
bool	Form::messege_visible = true;

Form::Form(const std::string &name, const int &singGrade, const int &executeGrade): _name(name), _singGrade(singGrade), _executeGrade(executeGrade)
{
	_isSigned = false;
	_chk_grade(singGrade);
	_chk_grade(executeGrade);
	if (Form::messege_visible)
		std::cout << "Default constructor (Form Class)" << std::endl;
	return ;
}

Form::Form(const Form &obj): _name(obj.getName()), _singGrade(obj.getSingGrade()), _executeGrade(obj.getExecuteGrade())
{
	if (Form::messege_visible)
		std::cout << "Copy constructor (Form Class)" << std::endl;
	*this = obj;
	return ;
}

Form::~Form(void)
{
	if (Form::messege_visible)
		std::cout << "Destructor (Form Class)" << std::endl;
	return ;
}

Form	&Form::operator=(const Form &obj)
{
	if (Form::messege_visible)
		std::cout << "Assignement operator (Form Class)" << std::endl;
	if (this != &obj)
		_isSigned = obj.getIsSigned();
	return *this;
}

const std::string	&Form::getName(void) const
{
	return (_name);
}

const bool	&Form::getIsSigned(void) const
{
	return (_isSigned);
}

const int	&Form::getSingGrade(void) const
{
	return (_singGrade);
}

const int	&Form::getExecuteGrade(void) const
{
	return (_executeGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _singGrade)
		throw Form::GradeTooLowException;
	else
		_isSigned = true;
}

void	Form::_chk_grade(int grade) const
{
	if (grade < Form::_max_grade)
		throw Form::GradeTooHighException;
	else if (grade > Form::_min_grade)
		throw Form::GradeTooLowException;
}

std::ostream	&operator<<(std::ostream &ostream, const Form &obj)
{
	ostream
		<< "Form - " << obj.getName()
		<< "(is signed: ";
	if (obj.getIsSigned())
		ostream << "YES";
	else
		ostream << "NO";
	ostream
		 << "), sing grade: " << obj.getSingGrade()
		 << ", execute grade: " << obj.getExecuteGrade();
	return ostream;
}
