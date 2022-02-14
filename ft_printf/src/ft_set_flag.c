/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:06:22 by msimon            #+#    #+#             */
/*   Updated: 2022/02/14 09:59:03 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_point_flag(const char **str, t_flags *f, va_list vl)
{
	if (**str == '*')
	{
		f->f_prec = va_arg(vl, int);
		*str += 1;
	}
	else if (ft_strchr(FT_PRINTF_NUMBER, **str) && **str)
		f->f_prec = ft_get_nmb(str);
	else
		f->f_prec = 0;
}

static void	set_h_flag(const char **str, t_flags *f)
{
	if (**str != 'h')
		f->f_h = 1;
	else
	{
		f->f_hh = 1;
		*str += 1;
	}
}

static void	set_l_flag(const char **str, t_flags *f)
{
	if (**str != 'l')
		f->f_l = 1;
	else
	{
		f->f_ll = 1;
		*str += 1;
	}
}

static void	set_size_flag(t_flags *f, va_list vl)
{
	f->f_size = va_arg(vl, int);
	if (f->f_size < 0)
	{
		f->f_size = f->f_size * -1;
		f->f_neg = 1;
	}
}

void	ft_set_flag(const char **str, t_flags *f, va_list vl)
{
	char	ch;

	ch = **str;
	*str += 1;
	if (ch == '0')
		f->f_zero = 1;
	else if (ch == '-')
		f->f_neg = 1;
	else if (ch == '*')
		set_size_flag(f, vl);
	else if (ch == '.')
		set_point_flag(str, f, vl);
	else if (ch == '#')
		f->f_hash = 1;
	else if (ch == ' ')
		f->f_space = 1;
	else if (ch == '+')
		f->f_pos = 1;
	else if (ch == 'h')
		set_h_flag(str, f);
	else if (ch == 'l')
		set_l_flag(str, f);
}
