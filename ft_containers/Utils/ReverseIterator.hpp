/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 13:00:53 by msimon            #+#    #+#             */
/*   Updated: 2022/06/27 16:30:01 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

# include "IteratorTraits.hpp"

namespace ft
{

	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			reverse_iterator(): baseIter() {}
			explicit reverse_iterator (iterator_type it): baseIter(it) {}
			
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it) {baseIter = rev_it.base();}
			
			template <class Iter>
			reverse_iterator& operator=(const reverse_iterator<Iter> &obj)
			{
				if (reinterpret_cast<reverse_iterator<Iter>* >(this) != 
					const_cast<reverse_iterator<Iter>* >(&obj))
					this->baseIter = obj.base();
				return *this;
			}

			iterator_type base() const {return baseIter;}
			reference operator*() const {iterator_type tmp = baseIter; return *--tmp;}
			pointer operator->() const {return &(operator*());}
			reference operator[](difference_type n) const {return base()[-n-1];}
			reverse_iterator &operator++() {--baseIter;	return *this;}
			reverse_iterator operator++(int) {reverse_iterator tmp = *this;	--baseIter;	return tmp;}
			reverse_iterator &operator--() {++baseIter;	return *this;}
			reverse_iterator operator--(int) {reverse_iterator tmp = *this;	++baseIter;	return tmp;}
			reverse_iterator operator+(difference_type n) const {return reverse_iterator(baseIter - n);}
			reverse_iterator operator-(difference_type n) const {return reverse_iterator(baseIter + n);}
			reverse_iterator operator+=(difference_type n) {baseIter -= n;return *this;}
			reverse_iterator operator-=(difference_type n) {baseIter += n;return *this;}

		private:
			iterator_type baseIter;
	};

# include "ReverseIterator.tpp"

}

#endif