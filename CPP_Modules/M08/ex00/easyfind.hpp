/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:06:25 by msimon            #+#    #+#             */
/*   Updated: 2022/02/05 17:50:23 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T &container, int val)
{
	typename T::iterator	i = container.begin();

	while (i != container.end())
	{
		if (*i == val)
			return (i);
		i++;
	}
	throw std::runtime_error("Value not found.");
	return (container.end());
}

#endif