/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:30:58 by msimon            #+#    #+#             */
/*   Updated: 2022/01/29 06:15:19 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

bool	ShrubberyCreationForm::messege_visible = true;

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): Form("shrubbery creation", 145, 137), _target(target)
{
	if (ShrubberyCreationForm::messege_visible)
		std::cout << "Default constructor (ShrubberyCreationForm Class)" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): Form("shrubbery creation", 145, 137), _target(obj.getTarget())
{
	*this = obj;
	if (ShrubberyCreationForm::messege_visible)
		std::cout << "Copy constructor (ShrubberyCreationForm Class)" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (ShrubberyCreationForm::messege_visible)
		std::cout << "Destructor (ShrubberyCreationForm Class)" << std::endl;
	return ;
}
		
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	(void)obj;
	if (ShrubberyCreationForm::messege_visible)
		std::cout << "Assignement operator (ShrubberyCreationForm Class)" << std::endl;
	return *this;
}

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw Form::noSignedForm;
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Form::GradeTooLowException;
	else
	{
		std::ofstream	myfile;
		std::string		fileName = this->_target + "_shrubbery";
		myfile.open(fileName.c_str(), std::ios::out);
		myfile << "  /\\" << std::endl;
		myfile << " /  \\" << std::endl;
		myfile << "/____\\" << std::endl;
		myfile << "  ||";
		myfile.close();
	}
	return ;
}
