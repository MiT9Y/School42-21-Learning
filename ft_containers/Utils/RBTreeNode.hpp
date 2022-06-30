/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeNode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:55:53 by msimon            #+#    #+#             */
/*   Updated: 2022/06/25 20:15:28 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREENODE_HPP
# define RBTREENODE_HPP

namespace ft
{

	template <class T>
	struct Node
	{
		Node*	l;
		Node*	r;
		Node*	par;
		T		val;
		bool	RED;

		Node(): l(NULL), r(NULL), par(NULL), val(), RED(0) {}
		Node(const T &data, Node* l, Node* r, Node* par, bool red):
			l(l), r(r), par(par), val(data), RED(red) {}
		~Node() {};
		Node(const Node& obj):
			l(obj.l), r(obj.r), par(obj.par), val(obj.val), RED(obj.RED) {}
		Node& operator=(const Node &obj)
		{
			if (this != &obj)
			{
				l = obj.l;
				r = obj.r;
				par = obj.par;
				val = obj.val;
				RED = obj.RED;
			}
			return *this;				
		}
	};
	
}

#endif
