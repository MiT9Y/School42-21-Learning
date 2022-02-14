/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nmb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:01:06 by msimon            #+#    #+#             */
/*   Updated: 2021/05/14 21:23:28 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_nmb(const char **str)
{
	int	i;

	i = 0;
	while (ft_strchr(FT_PRINTF_NUMBER, **str) && **str)
	{
		i++;
		*str += 1;
	}
	return (ft_atoi(*str - i));
}
