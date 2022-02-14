/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:10:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/28 21:42:53 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat::messege_visible = false;
	Form::messege_visible = false;
	PresidentialPardonForm::messege_visible = false;
	RobotomyRequestForm::messege_visible = false;
	ShrubberyCreationForm::messege_visible = false;

	try
	{	
		Bureaucrat	mad("MAD", 31);
		PresidentialPardonForm f1("BILL");
		RobotomyRequestForm f2("HOUSE");
		ShrubberyCreationForm f3("TREE");
		
		std::cout << mad << std::endl;
		std::cout << f1 << std::endl;

		std::cout << "***" << std::endl;
		mad.signForm(f1);
		mad.upGrade(10);
		mad.signForm(f1);
		mad.executeForm(f1);
		mad.upGrade(20);
		mad.executeForm(f1);

		std::cout << "***" << std::endl;
		mad.executeForm(f2);
		mad.downGrade(100);
		mad.signForm(f2);
		mad.upGrade(70);
		mad.signForm(f2);
		mad.executeForm(f2);

		std::cout << "***" << std::endl;
		mad.signForm(f3);
		mad.executeForm(f3);		
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (0);	
}
