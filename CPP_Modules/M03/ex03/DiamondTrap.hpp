/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 08:33:14 by msimon            #+#    #+#             */
/*   Updated: 2022/01/23 20:16:25 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &obj);
		~DiamondTrap(void);

		DiamondTrap		&operator=(const DiamondTrap &obj);
		
		void	attack(const std::string &target);
		void	whoAmI(void);
		const std::string	&get_name(void) const;

	private:
		std::string	_name;
		DiamondTrap(void);
};

std::ostream	&operator<<(std::ostream &ostream, const DiamondTrap &obj);

#endif
