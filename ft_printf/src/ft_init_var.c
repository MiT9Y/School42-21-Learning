/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:05:00 by msimon            #+#    #+#             */
/*   Updated: 2021/06/21 14:15:46 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_fr_str.h"

void	ft_init_var(t_flags *flags, char *prt_ch)
{
	if (flags->f_size < 0)
	{
		flags->f_neg = 1;
		flags->f_size *= -1;
	}
	if (flags->f_zero)
		*prt_ch = '0';
	else
		*prt_ch = ' ';
}
