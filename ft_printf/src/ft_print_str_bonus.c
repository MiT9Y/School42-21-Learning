/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:20:23 by msimon            #+#    #+#             */
/*   Updated: 2021/05/12 14:38:06 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_fr_str_bonus.h"

static void	init_var(t_flags flags, char *str, int *i)
{
	*i = ft_strlen(str);
	if (*i < 0)
		*i = 0;
	if (flags.f_prec < *i && flags.f_prec >= 0)
		*i = flags.f_prec;
}

int	ft_print_str(t_flags flags, char *str)
{
	int		res;
	char	prt_ch;
	int		str_l;

	if (!str)
		str = "(null)";
	ft_init_var(&flags, &prt_ch);
	init_var(flags, str, &res);
	str_l = res;
	if (flags.f_neg)
	{
		write(1, str, str_l);
		prt_ch = ' ';
	}
	while (flags.f_size > res)
	{
		write(1, &prt_ch, 1);
		res++;
	}
	if (!flags.f_neg)
		write(1, str, str_l);
	return (res);
}
