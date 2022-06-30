/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:13:14 by msimon            #+#    #+#             */
/*   Updated: 2022/06/28 11:52:14 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include <stdexcept>
# include "../Utils/RedBlackTree.hpp"
# include "../Utils/RBTreeIterator.hpp"
# include "../Utils/ReverseIterator.hpp"
# include "../Utils/PairUtils.hpp"
# include "../Utils/IteratorTraits.hpp"
# include "../Utils/Swap.hpp"
# include "../Utils/Equal.hpp"
# include "../Utils/LexicographicalCompare.hpp"

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		private:
			template <class U> struct not_const {typedef U type;};
			template <class U> struct not_const<const U> {typedef U type;};
			template <class U> struct not_const<U* const> {typedef U* type;};
			typedef ft::pair<typename not_const<Key>::type, typename not_const<T>::type>
				no_const_value_type;
		
		public:
			typedef Key											key_type;
			typedef T 											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			class												value_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::rb_tree_iterator<value_type, no_const_value_type>
																iterator;
			typedef ft::rb_tree_iterator<const value_type, no_const_value_type>
																const_iterator;
			typedef	ft::reverse_iterator<iterator>				reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef	std::ptrdiff_t								difference_type;
			typedef	std::size_t									size_type;
		
		private:
			typedef ft::rb_tree<no_const_value_type,
				value_compare, allocator_type>					tree;
			tree			_tree;
			allocator_type	_alloc;
			key_compare		_comp;

		public:
			explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _tree(), _alloc(alloc), _comp(comp) {}
			template <class InputIterator>
  			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
       			const allocator_type& alloc = allocator_type(),
				typename ft::iterator_traits<InputIterator>::iterator_category* = 0): _tree(), _alloc(alloc), _comp(comp)
				{insert(first, last);}
			map(const map& x) { *this = x; }
			map& operator=(const map& x);
			~map(){}

			iterator				begin() {return iterator(_tree.min_node(_tree.get_root()), _tree.get_root(), _tree.get_nil());}
			const_iterator 			begin() const {return const_iterator(_tree.min_node(_tree.get_root()), _tree.get_root(), _tree.get_nil());}
			iterator				end() {return iterator(_tree.get_nil(), _tree.get_root(), _tree.get_nil());}
			const_iterator			end() const {return const_iterator(_tree.get_nil(), _tree.get_root(), _tree.get_nil());}
			reverse_iterator		rbegin() {return reverse_iterator(end());}
			const_reverse_iterator	rbegin() const {return const_reverse_iterator(end());}
			reverse_iterator		rend() {return reverse_iterator(begin());}
			const_reverse_iterator	rend() const {return const_reverse_iterator(begin());}

			bool		empty() const {return (_tree.size() == 0);}
			size_type	size() const {return _tree.size();}
			size_type	max_size() const {return _tree.max_size();}

			mapped_type&		operator[](const key_type& k);
			mapped_type&		at(const key_type& k);
			const mapped_type&	at(const key_type& k) const;

			ft::pair<iterator,bool>	insert(const value_type& val);
			iterator				insert(iterator position, const value_type& val);
			template <class InputIterator>
				void 				insert(InputIterator first, InputIterator last,
				typename ft::iterator_traits<InputIterator>::iterator_category* = 0);
				
			void		erase(iterator position) { _tree.erase(position.get_node());}
			size_type	erase(const key_type& k) {return _tree.erase(no_const_value_type(k, mapped_type()));}
			void		erase(iterator first, iterator last);
			void 		swap(map& x);
			void 		clear() {_tree.clear();}
			
			key_compare		key_comp() const {return key_compare();}
			value_compare	value_comp() const {return value_compare();}

			iterator		find(const key_type& k);
			const_iterator	find(const key_type& k) const;
			size_type		count(const key_type& k) const;
			iterator		lower_bound(const key_type& k);
			const_iterator	lower_bound(const key_type& k) const;
			iterator		upper_bound(const key_type& k);
			const_iterator	upper_bound(const key_type& k) const;
			
			ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
			ft::pair<iterator,iterator>				equal_range(const key_type& k);

			allocator_type	get_allocator() const {return _alloc;}

	};

# include "map.tpp"

}

#endif