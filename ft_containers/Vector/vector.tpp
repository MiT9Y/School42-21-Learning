/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:00:45 by msimon            #+#    #+#             */
/*   Updated: 2022/06/28 11:57:16 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
# define VECTOR_TPP

//	Constructor & destructor BEGIN

template < class T, class Alloc >
vector <T, Alloc>::vector(allocator_type const &alloc):
	_data(NULL), _alloc(alloc), _size(0), _capacity(0) {};

template < class T, class Alloc >
vector <T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc):
	_alloc(alloc), _size(n), _capacity(n)
{
	pointer	beg;
	pointer	end;
	
	_data = _alloc.allocate(n);
	beg = _data;
	end = _data + _size;
	while (beg != end)
	{
		_alloc.construct(beg, val);
		beg++;
	}
}

template < class T, class Alloc >
vector <T, Alloc>::vector(const vector& x):
	_alloc(x.get_allocator()), _size(x.size()), _capacity(x.size())
{
	size_type	i = -1;
	
	_data = _alloc.allocate(_size);
	while (++i < _size)
		_alloc.construct(_data + i, x[i]);
}

template < class T, class Alloc >
vector <T, Alloc>::~vector <T, Alloc>()
{
	_alloc.deallocate(_data, _capacity);
}

template < class T, class Alloc >
	template <class InputIterator>
vector <T, Alloc>::vector(InputIterator first, InputIterator last,
	const allocator_type& alloc, typename ft::iterator_traits<InputIterator>::iterator_category*):
	_size(last - first), _capacity(last - first), _alloc(alloc)
{
	pointer	beg;
	_data = _alloc.allocate(_size);
	beg = _data;
	while (first != last)
	{
		_alloc.construct(beg, *first);
		first++;
		beg++;
	}
}

template < class T, class Alloc >
vector <T, Alloc>& vector <T, Alloc>::operator=(const vector& x)
{
	if (this != &x)
	{
		size_type	i = -1;
		_alloc.deallocate(_data, _capacity);
		_size = x.size();
		_capacity = x.capacity();
		_alloc = x.get_allocator();
		_data = _alloc.allocate(_size);
		while (++i < _size)
			_alloc.construct(_data + i, x[i]);
	}
	return (*this);
}

//	Constructor & destructor END

//	Capacity BEGIN

template < class T, class Alloc >
void vector <T, Alloc>::resize(size_type n, value_type val)
{
	if (n < _size)
	{
		for (int i = _size; i >= n; i--)
			_alloc.destroy(_data + i);
	}
	else if (n > _size)
	{
		if (n > _capacity && n > _capacity * 2)
			reserve(n);
		else if (n > _capacity && n <= _capacity * 2)
			reserve( _capacity * 2);
		for (size_type i = _size; i < n; i++)
			_alloc.construct(_data + i, val);
	}
	_size = n;
}

template < class T, class Alloc >
void vector <T, Alloc>::reserve(size_type n)
{
	if (n > max_size())
		throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");

	if (n < _capacity)
		return;
	
	pointer _tmp_data = _alloc.allocate(n);
	for (size_type i = 0; i < _size; i++)
	{
		_alloc.construct(_tmp_data + i, _data[i]);
		_alloc.destroy(_data + i);
	}
	if (_data)
		_alloc.deallocate(_data, _capacity);
	_capacity = n;
	_data = _tmp_data;	
}

//	Capacity END

//	Element access BEGIN

template < class T, class Alloc >
typename vector <T, Alloc>::reference vector <T, Alloc>::at(size_type n)
{
	if (n < _size)
		return _data[n];
/*	throw std::out_of_range("vector::_M_range_check: __n (which is " + 
		 std::to_string(n) + ") >= this->size() (which is " + 
		 std::to_string(_size) + ")");*/
	throw std::out_of_range("vector");
}

template < class T, class Alloc >		
typename vector <T, Alloc>::const_reference vector <T, Alloc>::at(size_type n) const
{
	if (n < _size)
		return _data[n];
/*	throw std::out_of_range("vector::_M_range_check: __n (which is " + 
		 std::to_string(n) + ") >= this->size() (which is " + 
		 std::to_string(_size) + ")");*/
	throw std::out_of_range("vector");
}

//	Element access END

//	Modifiers BEGIN

template < class T, class Alloc >
	template <class InputIterator>
void vector <T, Alloc>::assign(InputIterator first, InputIterator last,
	typename ft::iterator_traits<InputIterator>::iterator_category*)
{
	clear();
	if (last - first > _capacity)
	{
		_alloc.deallocate(_data, _capacity);
		_capacity = last - first;
		_data = _alloc.allocate(_capacity);
	}
	_size = last - first;
	for (size_type i = 0; i < _size; i++)
	{
		_alloc.construct(_data + i, *first);
		first++;
	}
}

template < class T, class Alloc >
void vector <T, Alloc>::assign(size_type n, const_reference val)
{
	clear();
	if (n > _capacity)
	{
		_alloc.deallocate(_data, _capacity);
		_data = _alloc.allocate(n);
		_capacity = n;
	}
	_size = n;
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_data + i, val);
}
template < class T, class Alloc >
void vector <T, Alloc>::push_back(const_reference val)
{
	if (_size == _capacity) {
		if (_capacity == 0)
			reserve(1);
		else
			reserve(_capacity * 2);
	}
	_alloc.construct(_data + _size, val);
	_size++;
}

template < class T, class Alloc >
void vector <T, Alloc>::pop_back()
{
	if (_size > 0)
	{
		_size--;
		_alloc.destroy(_data + _size);
	}
}

template < class T, class Alloc >
typename vector <T, Alloc>::iterator vector<T, Alloc>::insert(iterator position, const_reference val)
{
	size_type	pos = position - begin();

	if (_size == _capacity)
	{
		size_type	new_capacity;
		size_type	i = 0;
		if (_capacity == 0)
			new_capacity = 1;
		else
			new_capacity = _capacity * 2;
		pointer	new_data = _alloc.allocate(new_capacity);
		for (; i < pos; i++)
			_alloc.construct(new_data + i, _data[i]);
		_alloc.construct(new_data + i, val);
		i++;
		for (; i <= _size; i++)
			_alloc.construct(new_data + i, _data[i - 1]);
		clear();
		_alloc.deallocate(_data, _capacity);
		_data = new_data;
		_capacity = new_capacity;
		_size = i;
	}
	else
	{
		for (size_type i = _size; i > pos; i--)
		{
			if (i < _size)
				_alloc.destroy(_data + i);
			_alloc.construct(_data + i, _data[i - 1]);
		}
		_alloc.destroy(_data + pos);
		_alloc.construct(_data + pos, val);
		_size++;
	}
	return (_data + pos);
}

template < class T, class Alloc >
void vector <T, Alloc>::insert(iterator position, size_type n, const_reference val)
{
	if (n == 0)
		return ;
	size_type	pos = position - begin();

	if (n > _capacity - _size)
	{
		size_type	new_capacity = n + _size;
		if (new_capacity < _size * 2)
			new_capacity = _size * 2;
		pointer	new_data;
		try
		{
			new_data = _alloc.allocate(new_capacity);
			size_type i = 0;
			for (; i < pos; i++)
				_alloc.construct(new_data + i, _data[i]);
			for (; i < (pos + n); i++)
				_alloc.construct(new_data + i, val);
			for (; i < (_size + n); i++)
				_alloc.construct(new_data + i, _data[i - n]);
			clear();
			_alloc.deallocate(_data, _capacity);
			_data = new_data;
			_capacity = new_capacity;
			_size = i;
		}
		catch(...)
		{
			for(size_type i = 0; i < new_capacity; i++)
				_alloc.destroy(new_data + i);
			_alloc.deallocate(new_data, new_capacity);
			throw;
		}
	}
	else
	{
		size_type i = _size + n - 1;
		for (; i > pos + n - 1; i--)
		{
			if (i < _size)
				_alloc.destroy(_data + i);
			_alloc.construct(_data + i, _data[i - n]);
		}
		for (; i >= pos ; i--)
		{
			_alloc.destroy(_data + i);
			_alloc.construct(_data + i, val);
			if (i == 0)
				break;
		}
		_size += n;
	}
}

template < class T, class Alloc >
	template <class InputIterator>
void vector <T, Alloc>::insert(iterator position, InputIterator first, InputIterator last,
	typename ft::iterator_traits<InputIterator>::iterator_category*)
{
	if (last <= first)
		return ;
	size_type	n = last - first;
	size_type	pos = position - begin();

	if (n > _capacity - _size)
	{

		size_type	new_capacity = n + _size;
		if (new_capacity < _size * 2)
			new_capacity = _size * 2;
		pointer	new_data;
		try
		{
			new_data = _alloc.allocate(new_capacity);
			size_type i = 0;
			for (; i < pos; i++)
				_alloc.construct(new_data + i, _data[i]);
			for (; i < (pos + n); i++)
			{
				_alloc.construct(new_data + i, *first);
				first++;
			}
			for (; i < (_size + n); i++)
				_alloc.construct(new_data + i, _data[i - n]);
			clear();
			_alloc.deallocate(_data, _capacity);
			_data = new_data;
			_capacity = new_capacity;
			_size = i;
		}
		catch(...)
		{
			for(size_type i = 0; i < new_capacity; i++)
				_alloc.destroy(new_data + i);
			_alloc.deallocate(new_data, new_capacity);
			throw;
		}
	}
	else
	{
		size_type i = _size + n - 1;
		for (; i > pos + n - 1; i--)
		{
			if (i < _size)
				_alloc.destroy(_data + i);
			_alloc.construct(_data + i, _data[i - n]);
		}
		for (; i >= pos; i--)
		{
			last--;
			_alloc.destroy(_data + i);
			_alloc.construct(_data + i, *last);
			if (i == 0)
				break;
		}
		_size += n;
	}
}

template < class T, class Alloc >
typename vector <T, Alloc>::iterator vector <T, Alloc>::erase(iterator position)
{
	size_type	pos = position - begin();
	_alloc.destroy(_data + pos);
	for (size_type i = pos; i < _size - 1; i++)
	{
		_alloc.destroy(_data + i);
		_alloc.construct(_data + i, _data[i + 1]);
	}
	_size--;
	return iterator(_data + pos);
}

template < class T, class Alloc >
typename vector <T, Alloc>::iterator vector <T, Alloc>::erase(iterator first, iterator last)
{
	size_type	pos = first - begin();
	size_type	n = last - first;
	size_type	i = pos;
	for (;i < pos + n; i++)
		_alloc.destroy(_data + i);
	for (;i < _size; i++)
	{
		_alloc.destroy(_data + i - n);
		_alloc.construct(_data + i - n, _data[i]);
	}
	_size -= n;
	return iterator(first);
}

template < class T, class Alloc >
void vector <T, Alloc>::swap(vector& x)
{
	struct  ft_swap
	{
		static void swap(pointer& a, pointer& b) {pointer c(a); a=b; b=c;}
		static void swap(allocator_type& a, allocator_type& b) {allocator_type c(a); a=b; b=c;}
		static void swap(size_type& a, size_type& b) {size_type c(a); a=b; b=c;}
	};

	ft_swap::swap(_data, x._data);
	ft_swap::swap(_size, x._size);
	ft_swap::swap(_capacity, x._capacity);
	ft_swap::swap(_alloc, x._alloc);
}
//	Modifiers END

//	Allocator BEGIN

template < class T, class Alloc >
typename vector <T, Alloc>::allocator_type vector <T, Alloc>::get_allocator() const
{
	return _alloc;
}

//	Allocator END

//	Non-member function overloads BEGIN

template < class T, class Alloc >
bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template < class T, class Alloc >
bool operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(lhs == rhs);
}

template < class T, class Alloc >
bool operator<(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template < class T, class Alloc >
bool operator>(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return rhs < lhs;
}

template < class T, class Alloc >
bool operator<=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(lhs > rhs);
}

template < class T, class Alloc >
bool operator>=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(lhs < rhs);
}

template <class T, class Alloc>
void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
{
	x.swap(y);
}

//	Non-member function overloads BEGIN

#endif