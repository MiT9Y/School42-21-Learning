/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 06:42:31 by msimon            #+#    #+#             */
/*   Updated: 2022/01/29 07:53:55 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define MESSEGES_ARR_LEN	3

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &obj);
		~Intern(void);

		Intern	&operator=(const Intern &obj);

		Form	*makeForm(const std::string &formName, const std::string &target);

		static bool	messege_visible;

	private:
		Form*	_getPresidentialPardonForm(const std::string &target);
		Form*	_getRobotomyRequestForm(const std::string &target);
		Form*	_getShrubberyCreationForm(const std::string &target);

		Form*							(Intern::*_arr_functions[MESSEGES_ARR_LEN])(const std::string&);
		const static std::runtime_error	errorFormName;
};

#endif
