/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:00:03 by msimon            #+#    #+#             */
/*   Updated: 2022/06/28 11:10:21 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TPP
# define MAP_TPP

template <class K, class T, class C, class A>
class 	map<K, T, C, A>::value_compare
{
	public:
		bool operator()(const no_const_value_type& lhs, const no_const_value_type& rhs) const
		{
			return key_compare()(lhs.first, rhs.first);
		}
};

template <class K, class T, class C, class A>
map<K, T, C, A>&	map<K, T, C, A>::operator=(const map& x)
{
	if (this != &x)
	{
		_tree = x._tree;
		_comp = x._comp;
		_alloc = x._alloc;
	}
	return *this;
}

template <class K, class T, class C, class A>
typename map<K, T, C, A>::mapped_type& map<K, T, C, A>::operator[](const key_type& k)
{
	ft::pair<typename tree::Node*, bool>	found = _tree.insert(no_const_value_type(k, mapped_type()));
	void*			res_v = &(found.first->val.second);
	mapped_type*	res_p = reinterpret_cast<mapped_type*>(res_v);
	return *res_p;
}

template <class K, class T, class C, class A>
typename map<K, T, C, A>::mapped_type&	map<K, T, C, A>::at(const key_type& k)
{
	typename tree::Node*	res = _tree.get_node(no_const_value_type(k, mapped_type()));
	if (res == _tree.get_nil())
		throw std::out_of_range("map::at");
	void*			res_v = &(res->val.second);
	mapped_type*	res_p = reinterpret_cast<mapped_type*>(res_v);
	return *res_p;
}

template <class K, class T, class C, class A>
const typename map<K, T, C, A>::mapped_type&	map<K, T, C, A>::at(const key_type& k) const
{
	const typename tree::Node*	res = (const_cast<tree*>(&_tree))->get_node(no_const_value_type(k, mapped_type()));
	if (res == _tree.get_nil())
		throw std::out_of_range("map::at");
	void*			res_v = &(res->val.second);
	const mapped_type*	res_p = reinterpret_cast<const mapped_type*>(res_v);
	return *res_p;
}

template <class K, class T, class C, class A>
ft::pair<typename map<K, T, C, A>::iterator, bool> map<K, T, C, A>::insert(const value_type& val)
{
	ft::pair<typename tree::Node*, bool>	ins = _tree.insert(no_const_value_type(val));
	return ft::make_pair(iterator(ins.first, _tree.get_root(), _tree.get_nil()), ins.second);
}

template <class K, class T, class C, class A>
typename map<K, T, C, A>::iterator	map<K, T, C, A>::insert(iterator position, const value_type& val)
{
	(void)position;
	ft::pair<typename tree::Node*, bool> ins = _tree.insert(no_const_value_type(val));
	return iterator(ins.first, _tree.get_root(), _tree.get_nil());
}

template <class K, class T, class C, class A>
	template <class InputIterator>
void	map<K, T, C, A>::insert(InputIterator first, InputIterator last,
	typename ft::iterator_traits<InputIterator>::iterator_category*)
{
	while (first != last)
	{
		insert(*first);
		first++;
	}
}

template <class K, class T, class C, class A>
void	map<K, T, C, A>::erase(iterator first, iterator last)
{
	iterator tmp = first;
	while (first != last)
	{
		first++;
		erase(tmp);
		tmp = first;
	}
}

template <class K, class T, class C, class A>
void	map<K, T, C, A>::swap(map& x)
{
	_tree.swap(x._tree);
	ft::swap(_alloc, x._alloc);
	ft::swap(_comp, x._comp);
}

template <class K, class T, class C, class A>
typename map<K, T, C, A>::iterator	map<K, T, C, A>::find(const key_type& k)
{
	return iterator(
		_tree.get_node(no_const_value_type(k, mapped_type())),
		_tree.get_root(), _tree.get_nil()
	);
}

template <class K, class T, class C, class A>
typename map<K, T, C, A>::const_iterator	map<K, T, C, A>::find (const key_type& k) const
{
	return const_iterator(
		_tree.get_node(no_const_value_type(k, mapped_type())),
		_tree.get_root(), _tree.get_nil()
	);
}

template <class K, class T, class C, class A>
typename map<K, T, C, A>::size_type		map<K, T, C, A>::count(const key_type& k) const
{
	return (
		(const_cast<tree*>(&_tree))->get_node(no_const_value_type(k, mapped_type())) !=_tree.get_nil()
	);
}

template <class K, class T, class C, class A>
typename map<K, T, C, A>::iterator	map<K, T, C, A>::lower_bound(const key_type& k)
{
	no_const_value_type	val(k, mapped_type());
	typename tree::Node* res = _tree.min_node(_tree.get_root(), &val);
	if (!res)
		res = _tree.get_nil();
	return iterator(res, _tree.get_root(), _tree.get_nil());
}

template <class K, class T, class C, class A>
typename map<K, T, C, A>::const_iterator	map<K, T, C, A>::lower_bound(const key_type& k) const
{
	no_const_value_type	val(k, mapped_type());
	typename tree::Node* res = _tree.min_node(_tree.get_root(), &val);
	if (!res)
		res = _tree.get_nil();
	return const_iterator(res, _tree.get_root(), _tree.get_nil());
}

template <class K, class T, class C, class A>
typename map<K, T, C, A>::iterator	map<K, T, C, A>::upper_bound(const key_type& k)
{
	iterator	it = lower_bound(k);
	if (it != end() && k == it->first)
		it++;
	return (it);
}

template <class K, class T, class C, class A>
typename map<K, T, C, A>::const_iterator	map<K, T, C, A>::upper_bound(const key_type& k) const
{
	const_iterator	it = lower_bound(k);
	if (it != end() && k == it->first)
		it++;
	return (it);	
}

template <class K, class T, class C, class A>
ft::pair<typename map<K, T, C, A>::const_iterator, typename map<K, T, C, A>::const_iterator>
	map<K, T, C, A>::equal_range (const key_type& k) const
{
	return ft::make_pair(lower_bound(k), upper_bound(k));
}

template <class K, class T, class C, class A>
ft::pair<typename map<K, T, C, A>::iterator, typename map<K, T, C, A>::iterator>
	map<K, T, C, A>::equal_range (const key_type& k)
{
	return ft::make_pair(lower_bound(k), upper_bound(k));
}

template <class K, class T, class C, class A>
bool operator==(const ft::map<K, T, C, A>& lhs, const ft::map<K, T, C, A>& rhs)
{
	ft::map<K, T, C, A> *	p_lhs = const_cast<ft::map<K, T, C, A> *>(&lhs);
	ft::map<K, T, C, A> *	p_rhs = const_cast<ft::map<K, T, C, A> *>(&rhs);
	return (lhs.size() == rhs.size() && ft::equal(p_lhs->begin(), p_lhs->end(), p_rhs->begin()));
}

template <class K, class T, class C, class A>
bool operator!=(const ft::map<K, T, C, A>& lhs, const ft::map<K, T, C, A>& rhs)
{
	return !(lhs == rhs);
}

template <class K, class T, class C, class A>
bool operator<(const ft::map<K, T, C, A>& lhs, const ft::map<K, T, C, A>& rhs)
{
	ft::map<K, T, C, A> *	p_lhs = const_cast<ft::map<K, T, C, A> *>(&lhs);
	ft::map<K, T, C, A> *	p_rhs = const_cast<ft::map<K, T, C, A> *>(&rhs);
	return ft::lexicographical_compare(p_lhs->begin(), p_lhs->end(), p_rhs->begin(), p_rhs->end());
}

template <class K, class T, class C, class A>
bool operator<=(const ft::map<K, T, C, A>& lhs, const ft::map<K, T, C, A>& rhs)
{
	return !(rhs < lhs);
}

template <class K, class T, class C, class A>
bool operator>(const ft::map<K, T, C, A>& lhs, const ft::map<K, T, C, A>& rhs)
{
	return rhs < lhs;
}

template <class K, class T, class C, class A>
bool operator>=(const ft::map<K, T, C, A>& lhs, const ft::map<K, T, C, A>& rhs)
{
	return !(rhs > lhs);
}

template <class K, class T, class C, class A>
void swap(ft::map<K, T, C, A>& lhs, ft::map<K, T, C, A>& rhs)
{
	lhs.swap(rhs);
}

#endif