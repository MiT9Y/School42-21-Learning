/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:21:14 by msimon            #+#    #+#             */
/*   Updated: 2021/05/15 20:55:05 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_fr_str.h"

int	ft_print_hex(t_flags flags, unsigned long long int val, char ch)
{
	int				res;
	char			*s_val;
	unsigned char	f_up;

	val = val & (unsigned int) -1;
	if (ch == 'x')
		f_up = 0;
	else
		f_up = 1;
	s_val = ft_hex_str(val, f_up, &flags);
	if (!s_val)
		return (-1);
	flags.f_zero = 0;
	flags.f_prec = -1;
	res = ft_print_str(flags, s_val);
	free(s_val);
	return (res);
}
