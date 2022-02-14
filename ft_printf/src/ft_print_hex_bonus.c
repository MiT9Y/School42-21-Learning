/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:21:14 by msimon            #+#    #+#             */
/*   Updated: 2021/05/15 19:46:40 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_fr_str_bonus.h"

static void	set_val(unsigned long long int *val, t_flags flags)
{
	if (flags.f_ll)
		*val = *val & (unsigned long long int) -1;
	else if (flags.f_l)
		*val = *val & (unsigned long int) -1;
	else if (flags.f_h)
		*val = *val & (unsigned short int) -1;
	else if (flags.f_hh)
		*val = *val & (unsigned char) -1;
	else
		*val = *val & (unsigned int) -1;
}

int	ft_print_hex(t_flags flags, unsigned long long int val, char ch)
{
	int				res;
	char			*s_val;
	unsigned char	f_up;

	set_val(&val, flags);
	if (!val)
		flags.f_hash = 0;
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
