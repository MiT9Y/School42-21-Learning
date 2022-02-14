/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:07:13 by msimon            #+#    #+#             */
/*   Updated: 2021/05/19 16:48:33 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_ch(const char **ch, int *r, unsigned long long int *r_n)
{
	write(1, *ch, 1);
	*ch += 1;
	*r += 1;
	*r_n += 1;
}

int	ft_printf(const char *str, ...)
{
	int						res;
	int						res_pr;
	unsigned long long int	res_n;
	va_list					vl;

	va_start(vl, str);
	res = 0;
	res_n = 0;
	while (*str)
	{
		if (*str != '%')
			write_ch(&str, &res, &res_n);
		else
		{
			res_pr = ft_print_fr_str(&str, vl, res);
			if (res_pr >= 0)
				res += res_pr;
			else
				return (res_pr);
			res_n += res_pr;
		}
	}
	va_end(vl);
	return (res);
}
