/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 08:11:54 by msimon            #+#    #+#             */
/*   Updated: 2022/02/03 08:22:42 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &var1, T &var2)
{
	T buf = var1;

	var1 = var2;
	var2 = buf;
}

template<typename T>
const T	&min(const T &var1, const T &var2)
{
	if (var1 < var2)
		return (var1);
	else
		return (var2);
}

template<typename T>
const T	&max(const T &var1, const T &var2)
{
	if (var1 > var2)
		return (var1);
	else
		return (var2);
}

#endif
