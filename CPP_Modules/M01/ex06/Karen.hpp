/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:30:53 by paulohl           #+#    #+#             */
/*   Updated: 2022/01/16 11:51:15 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>

# define MESSEGES_ARR_LEN	4

class Karen
{
	public:
		Karen(void);
		void		complain(std::string level);
		void		set_allow_level(std::string level);

	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
		void		other(void);
		std::string	_arr_messeges[MESSEGES_ARR_LEN];
		void		(Karen::*_arr_functions[MESSEGES_ARR_LEN + 1])(void);
		int			get_level_index(std::string level);
		int			_allow_level;
};

#endif
