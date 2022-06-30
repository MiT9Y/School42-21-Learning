/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 16:25:41 by msimon            #+#    #+#             */
/*   Updated: 2022/06/27 13:42:38 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP
#include "IteratorTraits.hpp"

namespace ft
{

	template <class InputIterator1, class InputIterator2>
		bool equal (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2)
	{
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  		bool equal (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
	
}

#endif