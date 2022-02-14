/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:10:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/29 08:07:18 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat::messege_visible = false;
	Form::messege_visible = false;
	PresidentialPardonForm::messege_visible = false;
	RobotomyRequestForm::messege_visible = false;
	ShrubberyCreationForm::messege_visible = false;
	Intern::messege_visible = false;

	int	arr_forms_len = 4;
	int	i;

	try
	{	
		Intern					i1;
		Intern					i2(i1);
		Form*					arr_form[arr_forms_len];
		Bureaucrat				mad("MAD", 31);

		try
		{
			i = -1;
			while (++i < arr_forms_len)
				arr_form[i] = NULL;
			arr_form[0] = i2.makeForm("presidential pardon", "BILL");
			arr_form[1] = i2.makeForm("robotomy request", "HOUSE");
			arr_form[2] = i2.makeForm("shrubbery creation", "TREE");
			arr_form[3] = i2.makeForm("shrubbery creation", "TREE");
			arr_form[3] = i2.makeForm("", "TREE");
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << mad << std::endl;
		std::cout << *arr_form[0] << std::endl;

		std::cout << "***" << std::endl;
		mad.signForm(*arr_form[0]);
		mad.upGrade(10);
		mad.signForm(*arr_form[0]);
		mad.executeForm(*arr_form[0]);
		mad.upGrade(20);
		mad.executeForm(*arr_form[0]);

		std::cout << "***" << std::endl;
		mad.executeForm(*arr_form[1]);
		mad.downGrade(100);
		mad.signForm(*arr_form[1]);
		mad.upGrade(70);
		mad.signForm(*arr_form[1]);
		mad.executeForm(*arr_form[1]);

		std::cout << "***" << std::endl;
		mad.signForm(*arr_form[2]);
		mad.executeForm(*arr_form[2]);

		i = -1;
		while (++i < arr_forms_len)
			if (arr_form[i])
				delete arr_form[i];
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (0);	
}
