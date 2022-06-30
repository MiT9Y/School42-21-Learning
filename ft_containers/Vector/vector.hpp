/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:14:56 by msimon            #+#    #+#             */
/*   Updated: 2022/06/27 16:44:56 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>
# include <stdexcept>
# include <string>
# include "../Utils/VectorIterator.hpp"
# include "../Utils/ReverseIterator.hpp"
# include "../Utils/LexicographicalCompare.hpp"
# include "../Utils/Equal.hpp"
# include "../Utils/IteratorTraits.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public:
//	Types
			typedef	T										value_type;
			typedef	Alloc									allocator_type;
			typedef	value_type&								reference;
			typedef	const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef	std::size_t								size_type;
			typedef	std::ptrdiff_t							difference_type;
			typedef	ft::vector_iterator<pointer>			iterator;
			typedef	ft::vector_iterator<const_pointer>		const_iterator;
			typedef	ft::reverse_iterator<iterator>			reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;


//	Constructor & destructor
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type& val = value_type(),
								const allocator_type& alloc= allocator_type());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(), 
					typename ft::iterator_traits<InputIterator>::iterator_category* = 0);
			vector(const vector& x);
			~vector();
			vector& operator=(const vector& x);

//	Iterators
			iterator 				begin() {return iterator(_data);}
			const_iterator			begin() const {return const_iterator(_data);}
			iterator				end() {return iterator(_data + _size);}
			const_iterator			end() const {return const_iterator(_data + _size);}
			reverse_iterator		rbegin() {return reverse_iterator(end());}
			const_reverse_iterator	rbegin() const {return const_reverse_iterator(end());}
			reverse_iterator		rend() {return reverse_iterator(begin());}
			const_reverse_iterator	rend() const {return const_reverse_iterator(begin());}			

//	Capacity
			size_type	size() const {return (_size);}
			size_type	max_size() const {return _alloc.max_size();}
			void		resize(size_type n, value_type val = value_type());
			size_type	capacity() const {return (_capacity);}
			bool		empty() const {if (_size == 0) return true; return false;}
			void		reserve(size_type n);

//	Element access
			reference		operator[](size_type n) {return _data[n];}
			const_reference	operator[](size_type n) const {return _data[n];}
			reference		at(size_type n);
			const_reference	at(size_type n) const;
      		reference		front() {return _data[0];}
			const_reference	front() const {return _data[0];}
			reference		back() {return _data[_size - 1];}
			const_reference	back() const {return _data[_size - 1];}			
			
//	Modifiers
			template <class InputIterator>
			void				assign(InputIterator first, InputIterator last,
				typename ft::iterator_traits<InputIterator>::iterator_category* = 0);
			void				assign(size_type n, const_reference val);
			void				push_back(const_reference val);
			void				pop_back();
			iterator			insert(iterator position, const_reference val);
			void				insert(iterator position, size_type n, const_reference val);
			template <class InputIterator>
			void				insert(iterator position, InputIterator first, InputIterator last,
				typename ft::iterator_traits<InputIterator>::iterator_category* = 0);
			iterator			erase(iterator position);
			iterator			erase(iterator first, iterator last);
			void				swap(vector& x);
			void				clear() {while(_size) pop_back();}
			value_type*			data() {return _data;}
			const value_type*	data() const {return _data;}

//	Allocator
			allocator_type	get_allocator() const;

		private:
			pointer			_data;
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
	};

# include "vector.tpp"

}

#endif