/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:46:53 by msimon            #+#    #+#             */
/*   Updated: 2022/01/27 23:11:53 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const std::string &name, const int &singGrade, const int &executeGrade);
		Form(const Form &obj);
		~Form(void);

		Form	&operator=(const Form &obj);

		const std::string	&getName(void) const;		
		const bool			&getIsSigned(void) const;
		const int			&getSingGrade(void) const;
		const int			&getExecuteGrade(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
		static bool			messege_visible;

	private:
		Form(void);

		const static std::range_error	GradeTooHighException;
		const static std::range_error	GradeTooLowException;
		const static int				_min_grade = 150;
		const static int				_max_grade = 1;

		const std::string	_name;
		bool				_isSigned;
		const int			_singGrade;
		const int			_executeGrade;

		void				_chk_grade(int grade) const;
};

std::ostream	&operator<<(std::ostream &ostream, const Form &obj);

#endif