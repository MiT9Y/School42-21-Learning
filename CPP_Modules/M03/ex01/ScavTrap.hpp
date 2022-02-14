/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:39:51 by msimon            #+#    #+#             */
/*   Updated: 2022/01/22 13:20:17 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &obj);
		~ScavTrap(void);

		void		attack(const std::string &target);
		void		guardGate(void);

	private:
		ScavTrap(void);
};

std::ostream	&operator<<(std::ostream &ostream, const ScavTrap &obj);

#endif