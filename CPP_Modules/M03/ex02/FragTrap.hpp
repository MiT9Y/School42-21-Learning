/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:42:27 by msimon            #+#    #+#             */
/*   Updated: 2022/01/22 15:33:59 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap: public ClapTrap
{
	public:
		FragTrap(const std::string name);
		FragTrap(const FragTrap &obj);
		~FragTrap(void);

		void	highFivesGuys(void);

	private:
		FragTrap(void);
};

std::ostream	&operator<<(std::ostream &ostream, const FragTrap &obj);

#endif