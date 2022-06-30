/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:17:48 by msimon            #+#    #+#             */
/*   Updated: 2022/06/20 17:34:08 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include "IteratorTraits.hpp"
# include <iterator>

namespace ft
{
	template <class _Iter>
	class vector_iterator
	{
		public:
			typedef _Iter														iterator_type;
			typedef std::random_access_iterator_tag								iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;

			vector_iterator(): _p(0) {};
			vector_iterator(pointer ptr): _p(ptr) {};
			~vector_iterator() {};
			vector_iterator(const vector_iterator &obj) {*this = obj;}
			vector_iterator &operator=(const vector_iterator &obj);
			operator vector_iterator<const value_type*>() const {
				return vector_iterator<const value_type*>(_p);
			}
			pointer			base() const {return _p;}
			pointer			operator->() const {return _p;}
			reference		operator*() const {return *_p;}
			vector_iterator	&operator--() {	_p--; return (*this);}
			vector_iterator	operator--(int) {vector_iterator tmp = *this; _p--;	return (tmp);}
			vector_iterator	&operator++() {	_p++; return (*this);}
			vector_iterator	operator++(int) {vector_iterator tmp = *this; _p++;	return (tmp);}
			vector_iterator	operator+(difference_type n) const	{return (_p + n);}
			vector_iterator	operator-(difference_type n) const {return (_p - n);}
			difference_type	operator+(const vector_iterator &it) {	return (_p + it.base());}
			difference_type operator-(const vector_iterator &it) { return (_p - it.base());}
			vector_iterator	&operator+=(difference_type n) {_p += n; return *this;}
			vector_iterator &operator-=(difference_type n) {_p -= n; return *this;}
			reference		operator[](difference_type n) const { return _p[n];}

		private:
    		iterator_type	_p;
	};

# include "VectorIterator.tpp"

}

#endif
