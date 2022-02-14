/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:23:53 by msimon            #+#    #+#             */
/*   Updated: 2022/01/28 10:41:46 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		virtual ~PresidentialPardonForm(void);
		
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &obj);

		const std::string	&getTarget(void) const;
		virtual void		execute(Bureaucrat const &executor) const;
		
		static bool						messege_visible;
	
	private:
		PresidentialPardonForm(void);

		std::string _target;
};

#endif
