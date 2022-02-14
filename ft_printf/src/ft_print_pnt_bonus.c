/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pnt_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:55:56 by msimon            #+#    #+#             */
/*   Updated: 2021/05/15 21:01:29 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_fr_str_bonus.h"

int	ft_print_pnt(t_flags flags, void *pnt)
{
	int		res;
	char	*val;

	flags.f_hash = 1;
	val = ft_hex_str((unsigned long long int) pnt, 0, &flags);
	if (!val)
		return (-1);
	flags.f_zero = 0;
	flags.f_prec = -1;
	res = ft_print_str(flags, val);
	free(val);
	return (res);
}
