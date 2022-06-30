/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:08:00 by msimon            #+#    #+#             */
/*   Updated: 2022/06/27 12:08:14 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREEITERATOR_HPP
# define RBTREEITERATOR_HPP

# include <iterator>
# include "IteratorTraits.hpp"
# include "RBTreeNode.hpp"
# include "PairUtils.hpp"

namespace ft
{
	template <class S, class T>
	class rb_tree_iterator
	{
		public:
			typedef S*															iterator_type;
			typedef std::bidirectional_iterator_tag								iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;

		private:
			typedef ft::Node<T>				Node;
			Node*							_p;
			Node*							_root;
			Node*							_nil;
			Node*							min_node(Node* root);
			Node*							max_node(Node* root);
			Node*							L_node(Node* pos);
			Node*							R_node(Node* pos);

		public:
			rb_tree_iterator(): _p(NULL), _root(NULL), _nil(NULL) {};
			rb_tree_iterator(Node* p, Node* root, Node* nil): _p(p), _root(root), _nil(nil)
				{if (!_p) _p = nil;}
			~rb_tree_iterator() {};
			rb_tree_iterator(const rb_tree_iterator &obj) {*this = obj;}
			rb_tree_iterator	&operator=(const rb_tree_iterator &obj);
			operator rb_tree_iterator<const S, T>() const {
				return rb_tree_iterator<const S, T>(_p, _root, _nil);
			}
			pointer				base() const;
			pointer				operator->() const;
			reference			operator*() const;
			rb_tree_iterator	&operator--();
			rb_tree_iterator	operator--(int);
			rb_tree_iterator	&operator++();
			rb_tree_iterator	operator++(int);

			Node*				get_node() {return _p;}
	};

	# include "RBTreeIterator.tpp"
}

#endif
