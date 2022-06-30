/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PairUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:49:15 by msimon            #+#    #+#             */
/*   Updated: 2022/06/06 12:49:02 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIRUTILS_HPP
# define PAIRUTILS_HPP

namespace ft
{
	template <class T1, class T2> struct pair
	{
		typedef	T1	first_type;
		typedef	T2	second_type;

		first_type	first;
		second_type	second;

		pair(): first(first_type()), second(second_type()) {}
		template<class U, class V> pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {}
		pair (const first_type& a, const second_type& b): first(a), second(b) {}
		pair& operator= (const pair& pr);
	};

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y) { return (pair<T1,T2>(x,y));}

	# include "PairUtils.tpp"
}

#endif