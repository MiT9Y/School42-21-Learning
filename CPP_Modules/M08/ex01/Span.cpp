/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:07:01 by msimon            #+#    #+#             */
/*   Updated: 2022/02/06 07:12:34 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n)
{
	_data = new std::multiset <int>;
	_maxSize = n;
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span::~Span(void)
{
	delete _data;
}

Span	&Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		delete _data;
		_data = new std::multiset <int>(*obj._data);
		_maxSize = obj._maxSize;
	}
	return (*this);
}

void	Span::addNumber(int val)
{
	if (_data->size() < _maxSize)
		_data->insert(val);
	else
		throw std::overflow_error("Number is not ADD. Span is full.");
}

unsigned int	Span::shortestSpan(void) const
{
	if (_data->size() > 1)
	{
		std::multiset <int>::iterator	it = _data->begin();
		std::multiset <int>::iterator	itEnd = _data->end();
		unsigned int					res = std::numeric_limits <unsigned int>::max();
		unsigned int					tmp;

		itEnd--;
		itEnd--;
		while (it != itEnd)
		{
			tmp = *it;
			it++;
			tmp = *it - tmp;
			if (!tmp)
				return (tmp);
			else if (tmp < res)
				res = tmp;
		}
		return (res);
	}
	else
		throw std::underflow_error("Size of SPAN must be more one");
}

unsigned int	Span::longestSpan(void) const
{
	if (_data->size() > 1)
		return (*(--_data->end()) - *(_data->begin()));
	else
		throw std::underflow_error("Size of SPAN must be more one");
}
