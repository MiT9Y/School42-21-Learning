/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:10:27 by msimon            #+#    #+#             */
/*   Updated: 2021/05/12 14:13:27 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_fr_str_bonus.h"

int	ft_print_chr(t_flags flags, char chr)
{
	int		res;
	char	prt_ch;

	res = 1;
	ft_init_var(&flags, &prt_ch);
	if (flags.f_neg)
	{
		write(1, &chr, 1);
		prt_ch = ' ';
	}
	while (flags.f_size > 1)
	{
		write(1, &prt_ch, 1);
		flags.f_size--;
		res++;
	}
	if (!flags.f_neg)
		write(1, &chr, 1);
	return (res);
}
