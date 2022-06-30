/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:53:19 by msimon            #+#    #+#             */
/*   Updated: 2022/06/27 16:34:15 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_TPP
# define REVERSEITERATOR_TPP

	template <class Iterator1, class Iterator2>
	bool operator== (const reverse_iterator<Iterator1>& lhs,
					const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator1, class Iterator2>
		bool operator!= (const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator1, class Iterator2>
		bool operator<  (const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() > rhs.base();
	}					

	template <class Iterator1, class Iterator2>
		bool operator<= (const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class Iterator1, class Iterator2>
		bool operator>  (const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class Iterator1, class Iterator2>
		bool operator>= (const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

#endif