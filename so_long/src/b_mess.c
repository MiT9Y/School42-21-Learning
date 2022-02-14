/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_mess.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:23:28 by msimon            #+#    #+#             */
/*   Updated: 2021/07/30 15:25:55 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_base.h"

void	pr_error(char *str, char fl)
{
	ft_putstr_fd("Error\n", 2);
	if (fl == 0)
		ft_putstr_fd(str, 2);
	else
		perror(str);
	exit(1);
}
