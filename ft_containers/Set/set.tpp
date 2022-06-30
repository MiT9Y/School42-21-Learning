/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:05:24 by msimon            #+#    #+#             */
/*   Updated: 2022/06/28 11:12:24 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TPP
# define SET_TPP

template <class T, class C, class A>
set<T, C, A> &	set<T, C, A>::operator=(const set& x)
{
	if (this != &x)
	{
		_tree = x._tree;
		_comp = x._comp;
		_alloc = x._alloc;
	}
	return *this;
}

template <class T, class C, class A>
ft::pair<typename set<T, C, A>::iterator, bool> set<T, C, A>::insert(const value_type& val)
{
	ft::pair<typename tree::Node*, bool>	ins = _tree.insert(no_const_value_type(val));
	return ft::make_pair(iterator(ins.first, _tree.get_root(), _tree.get_nil()), ins.second);
}

template <class T, class C, class A>
typename set<T, C, A>::iterator	set<T, C, A>::insert(iterator position, const value_type& val)
{
	(void)position;
	ft::pair<typename tree::Node*, bool> ins = _tree.insert(no_const_value_type(val));
	return iterator(ins.first, _tree.get_root(), _tree.get_nil());
}

template <class T, class C, class A>
	template <class InputIterator>
void	set<T, C, A>::insert(InputIterator first, InputIterator last,
	typename ft::iterator_traits<InputIterator>::iterator_category*)
{
	while (first != last)
	{
		insert(*first);
		first++;
	}
}

template <class T, class C, class A>
void	set<T, C, A>::erase(iterator first, iterator last)
{
	iterator tmp = first;
	while (first != last)
	{
		first++;
		erase(tmp);
		tmp = first;
	}
}

template <class T, class C, class A>
void	set<T, C, A>::swap(set& x)
{
	_tree.swap(x._tree);
	ft::swap(_alloc, x._alloc);
	ft::swap(_comp, x._comp);
}

template <class T, class C, class A>
typename set<T, C, A>::iterator		set<T, C, A>::find(const value_type& val) const
{
	tree*	p_tree = const_cast<tree*>(&_tree);
	return iterator(
		p_tree->get_node(no_const_value_type(val)),
		p_tree->get_root(), _tree.get_nil()
	);

}

template <class T, class C, class A>
typename set<T, C, A>::size_type	set<T, C, A>::count(const value_type& val) const
{
	return (
		(const_cast<tree*>(&_tree))->get_node(no_const_value_type(val)) !=_tree.get_nil()
	);
}

template <class T, class C, class A>
typename set<T, C, A>::iterator		set<T, C, A>::lower_bound(const value_type& val) const
{
	no_const_value_type	n_val(val);
	tree*	p_tree = const_cast<tree*>(&_tree);
	typename tree::Node* res = p_tree->min_node(p_tree->get_root(), &n_val);
	if (!res)
		res = _tree.get_nil();
	return iterator(res, p_tree->get_root(), _tree.get_nil());
}

template <class T, class C, class A>
typename set<T, C, A>::iterator		set<T, C, A>::upper_bound(const value_type& val) const
{
	no_const_value_type	n_val(val);
	tree*	p_tree = const_cast<tree*>(&_tree);
	typename tree::Node* res = p_tree->min_node(p_tree->get_root(), &n_val);
	if (!res)
		res = _tree.get_nil();
	else if (val == res->val)
		res = p_tree->R_node(res);
	return iterator(res, p_tree->get_root(), _tree.get_nil());
}

template <class T, class C, class A>
	ft::pair<typename set<T, C, A>::iterator, typename set<T, C, A>::iterator>
	set<T, C, A>::equal_range(const value_type& val) const
{
	return ft::make_pair(lower_bound(val), upper_bound(val));	
}

template <class T, class Compare, class Alloc>
	bool operator==(const ft::set<T,Compare,Alloc>& lhs,
					const ft::set<T,Compare,Alloc>& rhs)
{
	ft::set<T, Compare, Alloc> *	p_lhs = const_cast<ft::set<T, Compare, Alloc> *>(&lhs);
	ft::set<T, Compare, Alloc> *	p_rhs = const_cast<ft::set<T, Compare, Alloc> *>(&rhs);
	return (lhs.size() == rhs.size() && ft::equal(p_lhs->begin(), p_lhs->end(), p_rhs->begin()));
	
}

template <class T, class Compare, class Alloc>
	bool operator!=(const ft::set<T,Compare,Alloc>& lhs,
					const ft::set<T,Compare,Alloc>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class Compare, class Alloc>
	bool operator< (const ft::set<T,Compare,Alloc>& lhs,
					const ft::set<T,Compare,Alloc>& rhs)
{
	ft::set<T, Compare, Alloc> *	p_lhs = const_cast<ft::set<T, Compare, Alloc> *>(&lhs);
	ft::set<T, Compare, Alloc> *	p_rhs = const_cast<ft::set<T, Compare, Alloc> *>(&rhs);
	return ft::lexicographical_compare(p_lhs->begin(), p_lhs->end(), p_rhs->begin(), p_rhs->end());
}

template <class T, class Compare, class Alloc>
bool operator<=(const ft::set<T,Compare,Alloc>& lhs,
				const ft::set<T,Compare,Alloc>& rhs)
{
	return !(rhs < lhs);	
}

template <class T, class Compare, class Alloc>
	bool operator> (const ft::set<T,Compare,Alloc>& lhs,
					const ft::set<T,Compare,Alloc>& rhs)
{
	return rhs < lhs;	
}

template <class T, class Compare, class Alloc>
	bool operator>=(const ft::set<T,Compare,Alloc>& lhs,
					const ft::set<T,Compare,Alloc>& rhs)
{
	return !(rhs > lhs);
}

template <class T, class Compare, class Alloc>
	void swap (ft::set<T,Compare,Alloc>& x, ft::set<T,Compare,Alloc>& y)
{
	x.swap(y);	
}

#endif