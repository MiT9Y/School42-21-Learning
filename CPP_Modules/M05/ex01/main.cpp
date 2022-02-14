/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:10:57 by msimon            #+#    #+#             */
/*   Updated: 2022/01/27 23:26:47 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat::messege_visible = false;
	Form::messege_visible = false;

	try
	{	
		Bureaucrat	mad("MAD", 150);
		Form		form1("FORM1", 100, 50);
		Form		form2(form1);
		
		form2 = form1;
		std::cout << form1 << std::endl;
		mad.signForm(form1);
		mad.upGrade(70);
		std::cout << mad << std::endl;
		mad.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (0);	
}
