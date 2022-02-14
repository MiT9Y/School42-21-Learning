/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:31:41 by msimon            #+#    #+#             */
/*   Updated: 2022/01/27 16:55:19 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::range_error	Bureaucrat::GradeTooHighException("Grade too high exception");
const std::range_error	Bureaucrat::GradeTooLowException("Grade too low exception");

Bureaucrat::Bureaucrat(const std::string &name, const int &grade): _name(name)
{
	_grade = grade;
	_chk_grade(grade);
	if (Bureaucrat::_messege_visible)
		std::cout << "Default constructor (Bureaucrat Class)" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj.getName())
{
	if (Bureaucrat::_messege_visible)
		std::cout << "Copy constructor (Bureaucrat Class)" << std::endl;
	*this = obj;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	if (Bureaucrat::_messege_visible)
		std::cout << "Destructor (Bureaucrat Class)" << std::endl;
	return ;		
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (Bureaucrat::_messege_visible)
		std::cout << "Assignement operator (Bureaucrat Class)" << std::endl;
	if (this != &obj)
		_grade = obj.getGrade();
	return *this;
}

const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
}

const int	&Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::upGrade(int val)
{
	_chk_grade(_grade - val);
	_grade -= val;
	return ;
}

void	Bureaucrat::downGrade(int val)
{
	_chk_grade(_grade + val);
	_grade += val;
	return ;	
}

void	Bureaucrat::_chk_grade(int grade) const
{
	if (grade < Bureaucrat::_max_grade)
		throw Bureaucrat::GradeTooHighException;
	else if (grade > Bureaucrat::_min_grade)
		throw Bureaucrat::GradeTooLowException;
}

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &obj)
{
	ostream
		<< obj.getName() << ", bureaucrat grade "
		<< obj.getGrade() << ".";
	return ostream;
}
