/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:59:03 by msimon            #+#    #+#             */
/*   Updated: 2021/05/14 21:25:13 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flag(t_flags *fl)
{
	fl->f_neg = 0;
	fl->f_zero = 0;
	fl->f_size = 0;
	fl->f_prec = -1;
	fl->f_pos = 0;
	fl->f_space = 0;
	fl->f_hash = 0;
	fl->f_l = 0;
	fl->f_ll = 0;
	fl->f_h = 0;
	fl->f_hh = 0;
}
