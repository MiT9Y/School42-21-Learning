/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnableIf.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:28:39 by msimon            #+#    #+#             */
/*   Updated: 2022/05/15 16:13:33 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLEIF_HPP
# define ENABLEIF_HPP

namespace ft
{
	
	template<bool Cond, class T = void> struct enable_if {};
	
	template<class T> struct enable_if<true, T>
	{
		typedef T type;
	};

	template <typename T, typename U> struct is_same
	{
	    static const bool value = false;
	};

	template <typename T> struct is_same <T, T>
	{
	    static const bool value = true;
	};
}

#endif