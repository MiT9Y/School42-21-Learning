/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:02:59 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 12:00:34 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		static const int	n_ideas = 100;

		Brain(void);
		Brain(const Brain &obj);
		~Brain(void);
	
		Brain	&operator=(const Brain &obj);

		std::string (&get_ideas(void))[100];
		const std::string get_idea(int i) const;

	private:
		std::string	_ideas[100];
};

#endif