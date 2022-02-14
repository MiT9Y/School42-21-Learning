/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:57:05 by msimon            #+#    #+#             */
/*   Updated: 2022/01/24 18:08:41 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &obj);
		virtual ~WrongAnimal(void);

		WrongAnimal	&operator=(const WrongAnimal &obj);

		void				makeSound(void) const;
		const std::string	&getType(void) const;

	protected:
		std::string _type;
};

std::ostream	&operator<<(std::ostream &ostream, const WrongAnimal &obj);

#endif
