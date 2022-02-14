/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:32:11 by msimon            #+#    #+#             */
/*   Updated: 2022/02/03 16:13:56 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array
{
	public:
		Array<T>(void);
		Array <T>(unsigned int len);
		Array <T>(const Array <T> &obj);
		~Array <T>(void);

		Array <T>	&operator=(const Array <T> &obj);
		T			&operator[](const unsigned int id) const;
		
		const unsigned int	&size(void) const;

	private:
		const static std::overflow_error	errArrayIndex;

		unsigned int	_len;
		T				*_arr;
};

# include "Array.tpp"

#endif
