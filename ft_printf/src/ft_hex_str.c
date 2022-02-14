/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:21:00 by msimon            #+#    #+#             */
/*   Updated: 2021/05/15 21:28:52 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_hash(char *str, unsigned char hash, unsigned char l)
{
	if (hash)
	{
		str[0] = '0';
		str[1] = l + 33;
	}
	return ;
}

static size_t	get_size(unsigned long long int nmb, t_flags *f)
{
	size_t	res;

	if (!f->f_prec && !nmb)
		return (f->f_hash * 2);
	res = 0;
	if (!nmb)
		res = 1;
	while (nmb > 0)
	{
		res++;
		nmb = nmb >> 4;
	}	
	if (f->f_prec >= 0)
	{
		if (f->f_prec > (int) res)
			res = f->f_prec + (f->f_hash * 2);
		else
			res += (f->f_hash * 2);
	}
	else if (f->f_zero && f->f_size > (int) res + (f->f_hash * 2) && !f->f_neg)
		res = f->f_size;
	else
		res += (f->f_hash * 2);
	return (res);
}

static void	set_hex_val(char *res, size_t *len,	unsigned char level,
				unsigned long long int nmb)
{
	unsigned char	val;

	if (nmb == 0)
		res[--*len] = 48;
	else
	{
		while (nmb > 0)
		{
			*len -= 1;
			val = nmb & 15;
			if (val > 9)
				res[*len] = level + val;
			else
				res[*len] = val + 48;
			nmb = nmb >> 4;
		}
	}
}

char	*ft_hex_str(unsigned long long int nmb,
			unsigned char up, t_flags *f)
{
	unsigned char	level;
	unsigned char	d_hash;
	char			*res;
	size_t			len;			

	if (up)
		level = 55;
	else
		level = 87;
	len = get_size(nmb, f);
	res = malloc(len + 1);
	if (res)
	{
		res[len] = 0;
		set_hash(res, f->f_hash, level);
		d_hash = f->f_hash * 2;
		if (nmb || f->f_prec)
			set_hex_val(res, &len, level, nmb);
		while (len-- > d_hash)
			res[len] = 48;
	}
	return (res);
}
