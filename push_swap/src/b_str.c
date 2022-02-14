/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 07:48:27 by msimon            #+#    #+#             */
/*   Updated: 2021/07/11 23:01:18 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	join_str(char **str, char *buf)
{
	size_t	len_str;
	size_t	len_buf;
	char	*new_str;

	if (*str)
		len_str = ft_strlen(*str);
	else
		len_str = 0;
	if (buf)
		len_buf = ft_strlen(buf);
	else
		len_buf = 0;
	new_str = malloc(len_str + len_buf + 1);
	if (!new_str)
		pr_error("Error\n");
	new_str[len_str + len_buf] = 0;
	ft_memmove(new_str, *str, len_str);
	ft_memmove(new_str + len_str, buf, len_buf);
	free(*str);
	*str = new_str;
}
