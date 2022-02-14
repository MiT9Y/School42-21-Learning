/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:59:47 by msimon            #+#    #+#             */
/*   Updated: 2022/01/26 08:39:26 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &obj);
		~MateriaSource(void);

		MateriaSource		&operator=(const MateriaSource &other);

		virtual void		learnMateria(AMateria *materia);
		virtual AMateria	*createMateria(std::string const &type);

		const static int	arr_size = 4;

	private:
		AMateria	*_materias[MateriaSource::arr_size];
		int			_learn_index;
};

#endif
