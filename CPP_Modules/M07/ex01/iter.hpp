/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:29:03 by msimon            #+#    #+#             */
/*   Updated: 2022/02/03 10:47:08 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T *arr, unsigned int arrLen, void (*ft)(T &))
{
	unsigned int	i = -1;

	while (++i < arrLen)
		ft(arr[i]);
	return ;
}

#endif
