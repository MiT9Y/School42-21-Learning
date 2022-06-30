/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:13:48 by msimon            #+#    #+#             */
/*   Updated: 2022/06/28 11:48:45 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <memory>
# include "PairUtils.hpp"
# include "Swap.hpp"
# include "RBTreeNode.hpp"

namespace ft
{

	template <class T, class Compare, class Alloc>
	class rb_tree
	{
		public:
			typedef T												value_type;
			typedef ft::Node<value_type>							Node;
			typedef typename Alloc::template rebind<Node>::other	allocator_type;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef std::size_t 									size_type;
			typedef Compare											key_compare;

		private:
			pointer 			_root;
			pointer 			_nil;
			size_type			_size;
			allocator_type 		_alloc;
			key_compare			_comp;

		public:
			rb_tree();		
			~rb_tree();
			rb_tree(const rb_tree &obj) {*this = obj;}
			rb_tree&	operator=(const rb_tree& obj);
			
			void 					clear() {clear_tree(_root);_root = _nil;}
			ft::pair<pointer,bool>	insert(const value_type& val);
			bool					erase(const value_type& key);
			void					erase(pointer node);
			const pointer			get_nil() const {return _nil;}
			pointer					get_root() {return _root;}
			pointer					get_node(const value_type& key);
			pointer					min_node(const pointer root, const value_type* min = NULL);
			pointer					max_node(const pointer root, const value_type* max = NULL);
			size_type 				size() const {return _size;}
			size_type 				max_size() const {return _alloc.max_size();}
			void					swap(rb_tree& x);
			pointer					L_node(const pointer pos);
			pointer					R_node(const pointer pos);
		
		private:
			void 	clear_tree(pointer root);
			void	copy_node(pointer src, pointer src_nil, pointer& dst, pointer dst_par);
			void	fix_insert(pointer node);
			void	rotate_left(pointer n);
			void	rotate_right(pointer n);
			pointer	found_node(const value_type& key);
			void	replace_on_child(pointer n);
			void	fix_erase(pointer par, pointer u);
			void	fix_erase_red_par(pointer par, pointer u);
			void	fix_erase_black_par(pointer par, pointer u);

	};

# include "RedBlackTree.tpp"

}

#endif
