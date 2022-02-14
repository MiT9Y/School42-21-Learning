/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:18:36 by msimon            #+#    #+#             */
/*   Updated: 2022/01/26 15:15:04 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
		Character(const std::string &name);
		Character(const Character &obj);
		virtual ~Character(void);

		Character	&operator=(const Character &obj);

		virtual std::string const	&getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
		
		const static int	arr_size = 4;

	private:
		Character(void);

		std::string			_name;
		AMateria			*_materias[Character::arr_size];
		int					_unequip_arr_index;
		const static int	_unequip_arr_size = Character::arr_size * 1000;
		AMateria			*_unequip_arr[Character::_unequip_arr_size];
};

#endif
