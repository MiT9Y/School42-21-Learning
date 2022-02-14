/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:14:55 by msimon            #+#    #+#             */
/*   Updated: 2022/01/25 12:02:27 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	int	i = -1;

	while (++i < Brain::n_ideas)
		_ideas[i] = "IDEA_" + std::to_string(i);
	std::cout << "Default constructor (Brain Class)" << std::endl;
	return ;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Copy constructor (Brain Class)" << std::endl;
	*this = obj;
	return ;
}
		
Brain::~Brain(void)
{
	std::cout << "Destructor (Brain Class)" << std::endl;
	return ;
}
	
Brain	&Brain::operator=(const Brain &obj)
{
	int	i = -1;
	
	std::cout << "Assignement operator (Brain Class)" << std::endl;
	if (this != &obj)
		while (++i < Brain::n_ideas)
			_ideas[i] = obj.get_idea(i);
	return (*this);
}

std::string (&Brain::get_ideas(void))[Brain::n_ideas]
{
	return (this->_ideas);
}

const std::string Brain::get_idea(int i) const
{
	if (i < 0 || i > Brain::n_ideas - 1)
		return ("");
	else
		return (this->_ideas[i]);
}
