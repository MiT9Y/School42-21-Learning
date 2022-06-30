/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.tpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:30:14 by msimon            #+#    #+#             */
/*   Updated: 2022/06/21 12:41:28 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_TPP
# define VECTORITERATOR_TPP

	template <class _Iter>
	vector_iterator<_Iter>	&vector_iterator<_Iter>::operator=(const vector_iterator &obj)
	{
		if (this != &obj)
			this->_p = obj.base();
		return (*this);
	}

	template <class _Iter>
	vector_iterator<_Iter> operator+(typename vector_iterator<_Iter>::difference_type n,
		const vector_iterator<_Iter> &rhs)
	{
		return (n + rhs);
	}

	template <class _Iter>
	vector_iterator<_Iter> operator+(const vector_iterator<_Iter> &lhs,
		typename vector_iterator<_Iter>::difference_type n)
	{
		return (lhs + n);
	}

	template <class _Iter>
	vector_iterator<_Iter> operator-(typename vector_iterator<_Iter>::difference_type n,
		const vector_iterator<_Iter> &rhs)
	{
		return (n - rhs);
	}

	template <class _Iter>
	vector_iterator<_Iter> operator-(const vector_iterator<_Iter> &lhs,
		typename vector_iterator<_Iter>::difference_type n)
	{
		return (lhs - n);
	}

	template <class Iter1, class Iter2>
	bool operator<(vector_iterator<Iter1> const &lhs, vector_iterator<Iter2> const &rhs)
	{
		return (lhs.base() < rhs.base());
	}
	
	template <class Iter1, class Iter2>
	bool operator<=(vector_iterator<Iter1> const &lhs, vector_iterator<Iter2> const &rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	
	template <class Iter1, class Iter2>
	bool operator>(vector_iterator<Iter1> const &lhs, vector_iterator<Iter2> const &rhs)
	{
		return (lhs.base() > rhs.base());
	}
	
	template <class Iter1, class Iter2>
	bool operator>=(vector_iterator<Iter1> const &lhs, vector_iterator<Iter2> const &rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	
	template <class Iter1, class Iter2>
	bool operator!=(vector_iterator<Iter1> const &lhs, vector_iterator<Iter2> const &rhs)
	{
		return (lhs.base() != rhs.base());
	}
	
	template <class Iter1, class Iter2>
	bool operator==(vector_iterator<Iter1> const &lhs, vector_iterator<Iter2> const &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	
#endif
