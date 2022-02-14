/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mess.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 06:47:39 by msimon            #+#    #+#             */
/*   Updated: 2021/06/15 15:25:35 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pr_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	pr_message(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}
