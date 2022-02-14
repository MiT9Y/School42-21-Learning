/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fr_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:58:17 by msimon            #+#    #+#             */
/*   Updated: 2021/06/21 14:54:29 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_fr_str.h"

static int	ft_print_type(char str, t_flags flags, va_list vl)
{
	int	res;

	if (str == 'c')
		res = ft_print_chr(flags, (char) va_arg(vl, int));
	else if (str == 's')
		res = ft_print_str(flags, va_arg(vl, char *));
	else if (str == 'p')
		res = ft_print_pnt(flags, va_arg(vl, void *));
	else if (str == 'x' || str == 'X')
		res = ft_print_hex(flags, va_arg(vl, unsigned long long int), str);
	else if (str == 'i' || str == 'd' || str == 'u')
		res = ft_print_nmb(flags, va_arg(vl, unsigned long long int), str);
	else
		res = ft_print_chr(flags, '%');
	return (res);
}

static int	set_n(va_list vl, unsigned long long int r)
{
	int	*i;

	i = va_arg(vl, int *);
	*i = r;
	return (0);
}

int	ft_print_fr_str(const char **str, va_list vl, unsigned long long int res_g)
{
	int		res;
	t_flags	flags;

	*str += 1;
	ft_init_flag(&flags);
	while (ft_strchr(FT_PRINTF_ALL, **str) && **str)
	{
		if (ft_strchr(FT_PRINTF_FLAGS, **str) && **str)
			ft_set_flag(str, &flags, vl);
		else if (ft_strchr(FT_PRINTF_NUMBER, **str) && **str)
			flags.f_size = ft_get_nmb(str);
	}
	if (ft_strchr(FT_PRINTF_TYPE, **str) && **str)
	{
		if (**str == 'n')
			res = set_n(vl, res_g);
		else
			res = ft_print_type(**str, flags, vl);
	}
	else if (**str)
		res = ft_print_chr(flags, **str);
	else
		return (0);
	*str += 1;
	return (res);
}
