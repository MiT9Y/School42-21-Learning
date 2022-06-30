/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:31:45 by msimon            #+#    #+#             */
/*   Updated: 2022/06/28 11:55:02 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREE_TPP
# define REDBLACKTREE_TPP

template <class T, class C, class A>
rb_tree<T, C, A>::rb_tree(): _root(NULL), _nil(NULL), _size(0)
{
	_comp = key_compare();
	_nil = _alloc.allocate(1);
	_alloc.construct(_nil, Node());
	_root = _nil;
}

template <class T, class C, class A>
rb_tree<T, C, A>::~rb_tree()
{
	clear();
	_alloc.destroy(_nil);
	_alloc.deallocate(_nil, 1);
}

template <class T, class C, class A>
rb_tree<T, C, A>&	rb_tree<T, C, A>::operator=(const rb_tree& obj)
{
	if (this != &obj)
	{
		clear();
		_alloc.destroy(_nil);
		_alloc.deallocate(_nil, 1);
		_comp = key_compare();
		_nil = _alloc.allocate(1);
		_alloc.construct(_nil, Node());
		_size = 0;
		copy_node(obj._root, obj._nil, _root, NULL);
	}	
	return *this;
}

template <class T, class C, class A>
void rb_tree<T, C, A>::copy_node(pointer src, pointer src_nil, pointer& dst, pointer dst_par)
{
	if (src == src_nil)
		{dst = _nil; return;}
	dst = _alloc.allocate(1);
	_alloc.construct(dst, Node());
	dst->par = dst_par;
	dst->val = src->val;
	dst->RED = src->RED;
	copy_node(src->l, src_nil, dst->l, dst);
	copy_node(src->r, src_nil, dst->r, dst);
	_size++;
}

template <class T, class C, class A>
void rb_tree<T, C, A>::clear_tree(pointer root)
{
	if (root == _nil)
		return ;
	clear_tree(root->l);
	clear_tree(root->r);
	_alloc.destroy(root);
	_alloc.deallocate(root, 1);
	_size--;
}

template <class T, class C, class A>
ft::pair<typename rb_tree<T, C, A>::pointer,bool>	rb_tree<T, C, A>::insert(const value_type& val)
{
	pointer new_node = _alloc.allocate(1);
	_alloc.construct(new_node, Node(val, _nil, _nil, NULL, 1));

	pointer par_node = NULL;
	pointer var_node = _root;
	while (var_node != _nil) {
		par_node = var_node;
		if (_comp(new_node->val, var_node->val))
			var_node = var_node->l;
		else if (_comp(var_node->val, new_node->val))
			var_node = var_node->r;
		else{
			_alloc.destroy(new_node);
			_alloc.deallocate(new_node, 1);
			return ft::make_pair(var_node, false);
		}
	}
	new_node->par = par_node;
	if (par_node == NULL)
		_root = new_node;
	else if (_comp(new_node->val, par_node->val))
		par_node->l = new_node;
	else
		par_node->r = new_node;
	_size++;

	fix_insert(new_node);
	return  ft::make_pair(new_node, true);
}

template <class T, class C, class A>
void	rb_tree<T, C, A>::fix_insert(pointer node)
{
	if (node->par == NULL) {node->RED = 0; return;}
	if (!node->par->RED) return;

	pointer	grand_node = node->par->par;	
	pointer	uncle_node = (grand_node->l == node->par) ? grand_node->r : grand_node->l;
	if (uncle_node->RED)
	{
		node->par->RED = 0;
		uncle_node->RED = 0;
		grand_node->RED = 1;
		fix_insert(grand_node);
	}
	else if (grand_node->l == node->par)
	{
		if (node == node->par->r) {node = node->par; rotate_left(node);}
		node->par->RED = 0;
		grand_node->RED = 1;
		rotate_right(grand_node);		
	}
	else
	{
		if (node == node->par->l) {node = node->par; rotate_right(node);}
		node->par->RED = 0;
		grand_node->RED = 1;
		rotate_left(grand_node);		
	}
}

template <class T, class C, class A>
void	rb_tree<T, C, A>::rotate_left(pointer n)
{
	pointer	pivot = n->r;
	
	pivot->par = n->par;
	if (n->par != NULL)
	{
		if (n->par->l == n)
			n->par->l = pivot;
		else
			n->par->r = pivot;
	}		
	else
		_root = pivot;
	n->r = pivot->l;
	if (pivot->l != _nil)
		pivot->l->par = n;
	n->par = pivot;
	pivot->l = n;
}

template <class T, class C, class A>
void	rb_tree<T, C, A>::rotate_right(pointer n)
{
    pointer	pivot = n->l;
	
    pivot->par = n->par;
    if (n->par != NULL)
	{
        if (n->par->l==n)
            n->par->l = pivot;
        else
            n->par->r = pivot;
    }
	else
		_root = pivot;
    n->l = pivot->r;
    if (pivot->r != _nil)
        pivot->r->par = n;
    n->par = pivot;
    pivot->r = n;
}

template <class T, class C, class A>
bool	rb_tree<T, C, A>::erase(const value_type& key)
{
	pointer	del_node = found_node(key);

	if (del_node == NULL)
		return false;

	replace_on_child(del_node);
	_size--;
	return true;
}

template <class T, class C, class A>
void	rb_tree<T, C, A>::erase(pointer node)
{
	replace_on_child(node);
	_size--;
}

template <class T, class C, class A>
typename rb_tree<T, C, A>::pointer	rb_tree<T, C, A>::found_node(const value_type& key)
{
	pointer	pos = _root;

	while (pos != _nil)
	{
		if (_comp(pos->val, key))
			pos = pos->r;
		else if (_comp(key, pos->val))
			pos = pos->l;
		else
			return pos;
	}
	return NULL;
}

template <class T, class C, class A>
typename rb_tree<T, C, A>::pointer	rb_tree<T, C, A>::get_node(const value_type& key)
{
	pointer	res = found_node(key);

	if (res == NULL)
		return _nil;
	return res;
}

template <class T, class C, class A>
void	rb_tree<T, C, A>::replace_on_child(pointer n)
{
	pointer	res;
	pointer u;
	
	if (n->l != _nil && n->r != _nil)
	{
		res = n->l;
		while (res->r != _nil)
			res = res->r;
		n->val = res->val;
		replace_on_child(res);
	}
	else
	{
		if (n->l != _nil)
			res = n->l;
		else
			res = n->r;
		if (n->par != NULL)
		{
			if (n->par->l == n)
			{
				n->par->l = res;
				u = n->par->r;
			}
			else
			{
				n->par->r = res;
				u = n->par->l;
			}
		}
		else
			_root = res;

		if (_root != _nil && res->RED != 1 && n->RED != 1 && u != _nil)
			fix_erase(u->par, u);
		if (res != _nil)
		{
			res->par = n->par;
			res->RED = 0;
		}

		_alloc.destroy(n);
		_alloc.deallocate(n, 1);
	}
}

template <class T, class C, class A>
void	rb_tree<T, C, A>::fix_erase(pointer par, pointer u)
{
	if (par->RED)
		fix_erase_red_par(par, u);
	else
		fix_erase_black_par(par, u);
}

template <class T, class C, class A>
void	rb_tree<T, C, A>::fix_erase_red_par(pointer par, pointer u)
{
	if (!(u->l->RED || u->r->RED))
	{
		u->RED = 1;
		par->RED = 0;
	}
	else
	{
		if (par->r == u)
		{
			if (u->r->RED)
				u->r->RED = 0;
			else
			{
				u->l->RED = 0;
				rotate_right(u);
			}
		}
		else
		{
			if (u->l->RED)
				u->l->RED = 0;
			else
			{
				u->r->RED = 0;
				rotate_left(u);
			}
		}
		if (par->r == u)
			rotate_left(par);
		else
			rotate_right(par);
		par->RED = 0;
	}
}

template <class T, class C, class A>
void	rb_tree<T, C, A>::fix_erase_black_par(pointer par, pointer u)
{
	if (u->RED)
	{
		pointer new_u;
		if (par->r == u)
		{	
			new_u = u->l;
			rotate_left(par);			
		}
		else
		{
			new_u = u->r;
			rotate_right(par);
		}
		u->RED = 0;
		par->RED = 1;
		fix_erase(par, new_u);
	}
	else if (!(u->l->RED || u->r->RED))
	{
		u->RED = 1;
		if (par->par != NULL)
		{
			if (par == par->par->l)
				fix_erase(par->par, par->par->r);
			else
				fix_erase(par->par, par->par->l);
		}
	}
	else
	{
		if (par->r == u)
		{
			if (u->r->RED)
				u->r->RED = 0;
			else
			{
				u->l->RED = 0;
				rotate_right(u);
			}
		}
		else
		{
			if (u->l->RED)
				u->l->RED = 0;
			else
			{
				u->r->RED = 0;
				rotate_left(u);
			}
		}
		if (par->r == u)
			rotate_left(par);
		else
			rotate_right(par);
	}
}

template <class T, class C, class A>
typename rb_tree<T, C, A>::pointer	rb_tree<T, C, A>::min_node(const pointer root, const value_type* min)
{
	pointer	pos = root;

	if (pos == _nil)
		return NULL;
	while (1)
	{
		if (min && !_comp(*min, pos->val))
		{
			if (!_comp(pos->val, *min))
				return pos;
			if (pos->r != _nil)
				pos = pos->r;
			else
			{
				while (pos != root->par)
				{
					if (_comp(*min, pos->val))
						return pos;
					pos = pos->par;
				}
				return NULL;
			}
		}
		else if (pos->l != _nil)
			pos = pos->l;
		else if (min && _comp(*min, pos->val))
			return pos;
		else if (min)
			return NULL;
		else
			return pos;
	}
}

template <class T, class C, class A>
typename rb_tree<T, C, A>::pointer	rb_tree<T, C, A>::max_node(const pointer root, const value_type* max)
{
	pointer	pos = root;

	if (pos == _nil)
		return NULL;
	while (1)
	{
		if (max && !_comp(pos->val, *max))
		{
			if (!_comp(*max, pos->val))
				return pos;
			if (pos->l != _nil)
				pos = pos->l;
			else
			{
				while (pos != root->par)
				{
					if (_comp(pos->val, *max))
						return pos;
					pos = pos->par;
				}
				return NULL;
			}
		}
		else if (pos->r != _nil)
			pos = pos->r;
		else if (max && _comp(pos->val, *max))
			return pos;
		else if (max)
			return NULL;
		else
			return pos;
	}
}

template <class T, class C, class A>
typename rb_tree<T, C, A>::pointer	rb_tree<T, C, A>::L_node(const pointer pos)
{
	if (pos == _nil || pos == NULL)
		return NULL;
	if (pos->l != _nil)
		return max_node(pos->l);
	else
	{
		pointer	p = pos;
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

template <class T, class C, class A>
typename rb_tree<T, C, A>::pointer	rb_tree<T, C, A>::R_node(const pointer pos)
{
	if (pos == _nil || pos == NULL)
		return NULL;
	if (pos->r != _nil)
		return min_node(pos->r);
	else
	{
		pointer	p = pos;
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

template <class T, class C, class A>
void	rb_tree<T, C, A>::swap(rb_tree& x)
{
	ft::swap(_root, x._root);
	ft::swap(_nil, x._nil);
	ft::swap(_size, x._size);
	ft::swap(_alloc, x._alloc);
	ft::swap(_comp, x._comp);
}

# endif
