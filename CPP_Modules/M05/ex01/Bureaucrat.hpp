/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:31:38 by msimon            #+#    #+#             */
/*   Updated: 2022/01/27 23:12:17 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &obj);

		const std::string	&getName(void) const;
		const int			&getGrade(void) const;
		void				upGrade(int val);
		void				downGrade(int val);
		void				signForm(Form &form) const;
		static bool			messege_visible;

	private:
		Bureaucrat(void);

		const static std::range_error	GradeTooHighException;
		const static std::range_error	GradeTooLowException;
		const static int				_min_grade = 150;
		const static int				_max_grade = 1;
		
		const std::string	_name;
		int					_grade;

		void				_chk_grade(int grade) const;
};

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &obj);

#endif