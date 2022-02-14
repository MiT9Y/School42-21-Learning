/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 20:57:51 by msimon            #+#    #+#             */
/*   Updated: 2022/01/28 21:13:34 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <ctime>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm: public Form
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		virtual ~RobotomyRequestForm(void);
		
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &obj);

		const std::string	&getTarget(void) const;
		virtual void		execute(Bureaucrat const &executor) const;
		
		static bool						messege_visible;
	
	private:
		RobotomyRequestForm(void);

		std::string _target;
};

#endif
