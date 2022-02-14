/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nmb_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:48:04 by msimon            #+#    #+#             */
/*   Updated: 2021/05/15 11:41:20 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_fr_str_bonus.h"

static void	set_zn(long long int val, char *zn,
				unsigned long long int	*u_val, t_flags f)
{
	if (val < 0)
	{
		*zn = '-';
		*u_val = val * -1;
	}
	else
	{
		if (f.f_pos)
			*zn = '+';
		else if (f.f_space)
			*zn = ' ';
		*u_val = val;
	}
}

static size_t	nmb_len(unsigned long long int nmb)
{
	size_t	res;

	res = 0;
	if (nmb == 0)
		res++;
	while (nmb > 0)
	{
		res++;
		nmb = nmb / 10;
	}
	return (res);
}

static size_t	get_len(t_flags flags, unsigned long long int nmb, char zn)
{
	size_t	res;
	char	zn_s;

	if (zn)
		zn_s = 1;
	else
		zn_s = 0;
	res = nmb_len(nmb);
	if (flags.f_prec == 0 && nmb == 0)
		return (zn_s);
	if (flags.f_prec >= 0)
	{
		if (res < (size_t) flags.f_prec)
			res = flags.f_prec + zn_s;
		else
			res += zn_s;
	}
	else if (flags.f_zero && ((size_t) flags.f_size > res + zn_s)
		&& !flags.f_neg)
		res = flags.f_size;
	else
		res += zn_s;
	return (res);
}

static void	get_t_nmb(unsigned long long int *nmb, char *zn, char ch, t_flags f)
{
	if (f.f_ll)
		*nmb = *nmb & (unsigned long long int) -1;
	else if (f.f_l)
		*nmb = *nmb & (unsigned long int) -1;
	else if (f.f_h)
		*nmb = *nmb & (unsigned short int) -1;
	else if (f.f_hh)
		*nmb = *nmb & (unsigned char) -1;
	else
		*nmb = *nmb & (unsigned int) -1;
	if (ch != 'u')
	{
		if (f.f_ll)
			set_zn((long long int) *nmb, zn, nmb, f);
		else if (f.f_l)
			set_zn((long int) *nmb, zn, nmb, f);
		else if (f.f_h)
			set_zn((short int) *nmb, zn, nmb, f);
		else if (f.f_hh)
			set_zn((char) *nmb, zn, nmb, f);
		else
			set_zn((int) *nmb, zn, nmb, f);
	}
}

int	ft_print_nmb(t_flags flags, unsigned long long int val, char ch)
{
	char					zn;
	size_t					len;
	char					*s_nmb;
	int						res;

	zn = 0;
	get_t_nmb(&val, &zn, ch, flags);
	len = get_len(flags, val, zn);
	s_nmb = ft_nmb_str(flags, val, zn, len);
	if (!s_nmb)
		return (-1);
	flags.f_zero = 0;
	flags.f_prec = -1;
	res = ft_print_str(flags, s_nmb);
	free(s_nmb);
	return (res);
}
