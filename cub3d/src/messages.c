/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:55:12 by msimon            #+#    #+#             */
/*   Updated: 2021/11/21 13:32:39 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	prt_error(char *str, char fl)
{
	ft_putstr_fd("Error\n", 2);
	if (fl == 0)
		ft_putstr_fd(str, 2);
	else
		perror(str);
	exit(1);
}
