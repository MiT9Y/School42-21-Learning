/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:14:25 by msimon            #+#    #+#             */
/*   Updated: 2022/02/03 17:35:08 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template<typename T>
const std::overflow_error	Array <T>::errArrayIndex("Incorrect index is use");

template<typename T>
Array <T>::Array(void)
{
	_len = 0;
	_arr = NULL;
}

template<typename T>
Array <T>::Array(unsigned int len)
{
	T				*val_def = new T();
	unsigned int	i = -1;

	_len = len;
	if (!_len)
	{
		_arr = NULL;
		return ;
	}
	_arr = new T[_len];
	while(++i < _len)
		_arr[i] = *val_def;
	delete val_def;
}

template<typename T>
Array <T>::Array(const Array <T> &obj)
{
	*this = obj;
}

template<typename T>
Array <T>::~Array <T>(void)
{
	if (_arr)
		delete [] _arr;
}

template<typename T>
Array <T>	&Array <T>::operator=(const Array <T> &obj)
{
	unsigned int	i;

	if (this != &obj)
	{
		if (_arr)
			delete [] _arr;
		_len = obj._len;
		if (_len)
			_arr = new T[_len];
		else
			_arr = NULL;
		i = -1;
		while (++i < _len)
			_arr[i] = obj[i];
	}
	return (*this);
}

template<typename T>
T	&Array <T>::operator[](const unsigned int id) const
{
	if (!(id < _len))
		throw Array::errArrayIndex;
	return _arr[id];
}

template<typename T>
const unsigned int	&Array <T>::size(void) const
{
	return _len;
}

#endif
