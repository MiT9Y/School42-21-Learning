/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:25:32 by msimon            #+#    #+#             */
/*   Updated: 2022/01/22 12:44:16 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &obj);
		~ClapTrap(void);

		ClapTrap		&operator=(const ClapTrap &obj);

		void			attack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		const std::string	&get_name(void) const;
		const unsigned int	&get_hitpoints(void) const;
		const unsigned int	&get_energy(void) const;
		const unsigned int	&get_damage(void) const;

	protected:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_max_hitpoints;
		unsigned int	_energy;
		unsigned int	_damage;

	private:
		ClapTrap(void);
};

std::ostream	&operator<<(std::ostream &ostream, const ClapTrap &obj);

#endif
