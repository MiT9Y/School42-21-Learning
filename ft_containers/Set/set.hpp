/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 08:36:19 by msimon            #+#    #+#             */
/*   Updated: 2022/06/28 11:59:30 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

# include <memory>
# include <functional>
# include "../Utils/RedBlackTree.hpp"
# include "../Utils/RBTreeIterator.hpp"
# include "../Utils/ReverseIterator.hpp"
# include "../Utils/IteratorTraits.hpp"
# include "../Utils/PairUtils.hpp"
# include "../Utils/Swap.hpp"
# include "../Utils/Equal.hpp"
# include "../Utils/LexicographicalCompare.hpp"

namespace ft
{
	template< class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		private:
			template <class U> struct not_const {typedef U type;};
			template <class U> struct not_const<const U> {typedef U type;};
			template <class U> struct not_const<U* const> {typedef U* type;};
			typedef typename not_const<T>::type	no_const_value_type;

		public:
			typedef T											key_type;
			typedef T											value_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
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
				value_compare, allocator_type>			tree;
			tree										_tree;
			allocator_type								_alloc;
			key_compare									_comp;
			
		public:
			explicit set(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()): _tree(), _alloc(alloc), _comp(comp) {}
			template <class InputIterator>
				set(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type(),
				typename ft::iterator_traits<InputIterator>::iterator_category* = 0): _tree(), _comp(comp), _alloc(alloc)
				{insert(first, last);}
			set(const set& x) {*this = x;}
			set& operator=(const set& x);
			~set() {}

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

			ft::pair<iterator,bool>	insert(const value_type& val);
			iterator				insert(iterator position, const value_type& val);
			template <class InputIterator>
				void 				insert(InputIterator first, InputIterator last,
				typename ft::iterator_traits<InputIterator>::iterator_category* = 0);
				
			void		erase(iterator position) {_tree.erase(position.get_node());}
			size_type	erase(const value_type& val) {return _tree.erase(no_const_value_type(val));}
			void		erase(iterator first, iterator last);
			void 		swap(set& x);
			void 		clear() {_tree.clear();}

			key_compare		key_comp() const {return key_compare();}
			value_compare	value_comp() const {return value_compare();}

			iterator		find(const value_type& val) const;
			size_type		count(const value_type& val) const;
			iterator		lower_bound(const value_type& val) const;
			iterator		upper_bound(const value_type& val) const;

			ft::pair<iterator,iterator>	equal_range(const value_type& val) const;

			allocator_type	get_allocator() const {return _alloc;}
	};

	# include "set.tpp"

}

#endif
