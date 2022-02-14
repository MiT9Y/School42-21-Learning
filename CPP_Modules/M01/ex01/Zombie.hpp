/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 08:41:13 by msimon            #+#    #+#             */
/*   Updated: 2022/01/12 12:41:41 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	public:
		Zombie(std::string val = std::string("Doe"));
		~Zombie(void);
		void		set_name(std::string val);
		std::string	get_name(void) const;
		void		announce(void) const;

	private:
		std::string	_name;
};

#endif