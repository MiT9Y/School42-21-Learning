/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:26:01 by msimon            #+#    #+#             */
/*   Updated: 2022/01/28 21:44:03 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		virtual ~ShrubberyCreationForm(void);
		
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &obj);

		const std::string	&getTarget(void) const;
		virtual void		execute(Bureaucrat const &executor) const;
		
		static bool						messege_visible;
	
	private:
		ShrubberyCreationForm(void);

		std::string _target;
};

#endif
