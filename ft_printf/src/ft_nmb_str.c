/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmb_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:05:32 by msimon            #+#    #+#             */
/*   Updated: 2021/05/15 07:35:15 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	write_nmb(char *str, unsigned long long int nmb, size_t len)
{
	if (nmb == 0)
	{
		len--;
		str[len] = 48;
		return (len);
	}
	while (nmb > 0)
	{
		len--;
		str[len] = (nmb % 10) + 48;
		nmb = nmb / 10;
	}
	return (len);
}

char	*ft_nmb_str(t_flags flags, unsigned long long int u_val,
			char zn, size_t len)
{
	char			*res;
	unsigned char	l_zn;

	if (zn)
		l_zn = 1;
	else
		l_zn = 0;
	res = malloc(len + 1);
	if (res)
	{
		res[len] = 0;
		if (zn)
			res[0] = zn;
		if (flags.f_prec == 0 && u_val == 0)
			return (res);
		len = write_nmb(res, u_val, len);
		while (len-- > l_zn)
			res[len] = 48;
	}
	return (res);
}
