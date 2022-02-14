/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pbook.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:47:18 by msimon            #+#    #+#             */
/*   Updated: 2022/01/10 21:42:26 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PBOOK_HPP
# define PBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class	Pbook
{
	public:
		void		add(void);
		int			show_contacts(void);
		int			show_contact(int intdex);

	private:
		Contact		contacts[8];
		static int	_count;
		int			get_contact_index(void);
};

#endif