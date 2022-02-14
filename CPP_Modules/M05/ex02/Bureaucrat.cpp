/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:31:41 by msimon            #+#    #+#             */
/*   Updated: 2022/01/28 21:11:57 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::range_error	Bureaucrat::GradeTooHighException("Grade too high exception (BUREAUCRAT)");
const std::range_error	Bureaucrat::GradeTooLowException("Grade too low exception (BUREAUCRAT)");
bool	Bureaucrat::messege_visible = true;

Bureaucrat::Bureaucrat(const std::string &name, const int &grade): _name(name)
{
	_grade = grade;
	_chk_grade(grade);
	if (Bureaucrat::messege_visible)
		std::cout << "Default constructor (Bureaucrat Class)" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj): _name(obj.getName())
{
	if (Bureaucrat::messege_visible)
		std::cout << "Copy constructor (Bureaucrat Class)" << std::endl;
	*this = obj;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	if (Bureaucrat::messege_visible)
		std::cout << "Destructor (Bureaucrat Class)" << std::endl;
	return ;		
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (Bureaucrat::messege_visible)
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

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout
			<< "Bureaucrat " << _name
			<< " signed form "<< form.getName()
			<< std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout
			<< "Bureaucrat " << _name
			<< " couldn’t sign form " << form.getName()
			<< " because his grade (" << _grade
			<< ") is too low for the form grade ("
			<< form.getSingGrade() << ")"
			<< std::endl;		
	}
	return ;
}

void	Bureaucrat::executeForm(const Form &form) const
{
	try
	{
		form.execute(*this);
		std::cout
			<< "Bureaucrat " << _name
			<< " executed form "<< form.getName()
			<< std::endl;
	}
	catch(const std::range_error &e)
	{
		std::cout
			<< "Bureaucrat " << _name
			<< " couldn’t execute form " << form.getName()
			<< " because his grade (" << _grade
			<< ") is too low for the form grade ("
			<< form.getExecuteGrade() << ")"
			<< std::endl;
	}
	catch(const std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
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
