/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorTraits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:57:36 by msimon            #+#    #+#             */
/*   Updated: 2022/05/13 09:10:41 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORTRAITS_HPP
# define ITERATORTRAITS_HPP

namespace ft
{

	template <class _Tp>
	struct __has_iterator_category
	{
		private:
			struct __two {char __lx; char __lxx;};
			template <class _Up> static __two __test(...);
			template <class _Up> static char __test(typename _Up::iterator_category* = 0);
		public:
			static const bool value = sizeof(__test<_Tp>(0)) == 1;
	};

	template <class _Iter, bool> struct __iterator_traits {};

	template <class _Iter> struct __iterator_traits <_Iter, true>
	{
		typedef typename _Iter::difference_type difference_type;
		typedef typename _Iter::value_type value_type;
		typedef typename _Iter::pointer pointer;
		typedef typename _Iter::reference reference;
		typedef typename _Iter::iterator_category iterator_category;
	};

	template <class _Iter> struct iterator_traits
    	: __iterator_traits<_Iter, __has_iterator_category<_Iter>::value> {};

	template <class T> struct iterator_traits <T*>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T> struct iterator_traits <const T*>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T> struct iterator_traits <T* const>
	{
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* const pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

}

#endif