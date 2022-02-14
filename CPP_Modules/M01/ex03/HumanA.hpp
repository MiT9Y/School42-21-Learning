/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 08:34:16 by msimon            #+#    #+#             */
/*   Updated: 2022/01/13 10:37:44 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name = "Doe", Weapon &weapon = *(new Weapon()));
	void	attack(void);

private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif
