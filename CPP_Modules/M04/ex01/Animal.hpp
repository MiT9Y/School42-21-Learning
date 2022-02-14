/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:53:31 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 14:24:19 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &obj);
		virtual ~Animal(void);

		Animal	&operator=(const Animal &obj);

		virtual void		makeSound(void) const;
		const std::string	&getType(void) const;
		Brain				*get_brain(void) const;

	protected:
		std::string _type;
		Brain	*_brain;
};

std::ostream	&operator<<(std::ostream &ostream, const Animal &obj);

#endif
