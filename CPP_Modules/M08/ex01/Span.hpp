/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:30:37 by msimon            #+#    #+#             */
/*   Updated: 2022/02/06 06:40:02 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <limits>
# include <stdexcept>
# include <algorithm>

class	Span
{
	public:
		Span(unsigned int n);
		Span(const Span &obj);
		~Span(void);

		Span	&operator=(const Span &obj);

		void			addNumber(int val);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		
		template <typename T>
		void	addItRange(T first, T last);

	private:
		Span(void);
		
		std::multiset <int>	*_data;
		unsigned int		_maxSize;
};

template <typename T>
void	Span::addItRange(T first, T last)
{
	if (_data->size() + std::distance(first, last) < _maxSize)
	{
		while (first != last)
		{
			_data->insert(*first);
			first++;
		}
	}
	else
		throw std::overflow_error("Range is not ADD. Span size + Range size more MAX size.");
}

#endif
