/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:46:41 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 20:23:26 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &obj);
		virtual ~Ice(void);

		Ice	&operator=(const Ice &obj);

		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif
