/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PairUtils.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:02:50 by msimon            #+#    #+#             */
/*   Updated: 2022/06/06 12:50:17 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIRUTILS_TPP
# define PAIRUTILS_TPP

	template <class T1, class T2>
	pair<T1,T2>& pair<T1,T2>::operator= (const pair& pr)
	{
		if (this != &pr)
		{
			this->first = pr.first;
			this->second = pr.second;
		}
		return *this;			
	}

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first) || (lhs.first == rhs.first && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);		
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);		
	}

#endif
