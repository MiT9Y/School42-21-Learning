/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:48:55 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 20:50:10 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &obj);
		virtual ~Cure(void);

		Cure	&operator=(const Cure &obj);

		virtual AMateria	*clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif
