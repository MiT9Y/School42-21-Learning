/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeIterator.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:40:46 by msimon            #+#    #+#             */
/*   Updated: 2022/06/27 16:00:40 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREEITERATOR_TPP
# define RBTREEITERATOR_TPP

template <class S, class T>
typename rb_tree_iterator<S, T>::Node*	rb_tree_iterator<S, T>::min_node(Node* root)
{
	if (root == _nil || root == NULL)
		return NULL;
	while (1)
	{
		if (root->l != _nil)
			root = root->l;
		else
			return root;
	}
}

template <class S, class T>
typename rb_tree_iterator<S, T>::Node*	rb_tree_iterator<S, T>::max_node(Node* root)
{
	if (root == _nil || root == NULL)
		return NULL;
	while (1)
	{
		if (root->r != _nil)
			root = root->r;
		else
			return root;
	}
}

template <class S, class T>
typename rb_tree_iterator<S, T>::Node*	rb_tree_iterator<S, T>::L_node(Node* pos)
{
	if (pos == _nil || pos == NULL)
		return NULL;
	if (pos->l != _nil)
		return max_node(pos->l);
	else
	{
		Node*	p = pos;
		while (p->par != NULL)
		{
			if (p == p->par->r)
				return p->par;
			else
				p = p->par;
		}
		return NULL;
	}
}

template <class S, class T>
typename rb_tree_iterator<S, T>::Node*	rb_tree_iterator<S, T>::R_node(Node* pos)
{
	if (pos == _nil || pos == NULL)
		return NULL;
	if (pos->r != _nil)
		return min_node(pos->r);
	else
	{
		Node*	p = pos;
		while (p->par != NULL)
		{
			if (p == p->par->l)
				return p->par;
			else
				p = p->par;
		}
		return NULL;
	}	
}

template <class S, class T>
rb_tree_iterator<S, T>	&rb_tree_iterator<S, T>::operator=(const rb_tree_iterator &obj)
{
	if (this != &obj)
	{
		this->_p = obj._p;
		this->_root = obj._root;
		this->_nil = obj._nil;
	}
	return (*this);
}

template <class S, class T>
rb_tree_iterator<S, T>	&rb_tree_iterator<S, T>::operator--()
{
	if (_p != _nil)
		_p = L_node(_p);
	else
		_p = max_node(_root);	
	if (!_p)
		_p = _nil;
	return (*this);
}

template <class S, class T>
rb_tree_iterator<S, T>	rb_tree_iterator<S, T>::operator--(int)
{
	rb_tree_iterator tmp = *this;
	if (_p != _nil)
		_p = L_node(_p);
	else
		_p = max_node(_root);	
	if (!_p)
		_p = _nil;
	return (tmp);
}

template <class S, class T>
rb_tree_iterator<S, T>	&rb_tree_iterator<S, T>::operator++()
{
	if (_p != _nil)
		_p = R_node(_p);
	else
		_p = max_node(_root);	
	if (!_p)
		_p = _nil;
	return (*this);
}

template <class S, class T>
rb_tree_iterator<S, T>	rb_tree_iterator<S, T>::operator++(int)
{
	rb_tree_iterator tmp = *this;
	if (_p != _nil)
		_p = R_node(_p);
	else
		_p = max_node(_root);	
	if (!_p)
		_p = _nil;
	return (tmp);
}

template <class S, class T>
typename rb_tree_iterator<S, T>::pointer	rb_tree_iterator<S, T>::base() const 
{
	void* tmp = &(_p->val);
	return reinterpret_cast<pointer>(tmp);
}

template <class S, class T>
typename rb_tree_iterator<S, T>::pointer	rb_tree_iterator<S, T>::operator->() const
{
	void* tmp = &(_p->val);
	return reinterpret_cast<pointer>(tmp);
}

template <class S, class T>
typename rb_tree_iterator<S, T>::reference rb_tree_iterator<S, T>::operator*() const
{
	void* tmp = &(_p->val);
	pointer tmp_p = reinterpret_cast<pointer>(tmp);
	return *tmp_p;
}

template <class S1, class T1, class S2, class T2>
bool operator!=(rb_tree_iterator<S1, T1> const &lhs, rb_tree_iterator<S2, T2> const &rhs)
{
	return (lhs.base() != rhs.base());
}

template <class S1, class T1, class S2, class T2>
bool operator==(rb_tree_iterator<S1, T1> const &lhs, rb_tree_iterator<S2, T2> const &rhs)
{
	return (lhs.base() == rhs.base());
}

#endif