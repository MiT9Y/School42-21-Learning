/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:34:47 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 20:38:58 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(const std::string &type);
		virtual ~AMateria(void);

		const std::string	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

#endif
