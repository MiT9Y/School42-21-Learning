/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LexicographicalCompare.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:13:00 by msimon            #+#    #+#             */
/*   Updated: 2022/06/03 10:16:31 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICALCOMPARE_HPP
# define LEXICOGRAPHICALCOMPARE_HPP

namespace ft
{

	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2,
			Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first2, *first1))
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);		
	}
}

#endif