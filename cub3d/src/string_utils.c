/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:48:28 by msimon            #+#    #+#             */
/*   Updated: 2021/11/19 08:33:25 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	str_join_char(char **str, char ch)
{
	char	*buf;
	int		len;

	buf = *str;
	len = ft_strlen(buf);
	*str = malloc(sizeof(char) * (len + 2));
	if (!*str)
		prt_error(ERR_MEM, 0);
	(*str)[len + 1] = 0;
	(*str)[len] = ch;
	ft_memcpy(*str, buf, len);
	free(buf);
}

int	get_next_word(char *str, char **cmd, int pos)
{
	int		i;
	char	start;

	*cmd = malloc(sizeof(char));
	if (!*cmd)
		prt_error(ERR_MEM, 0);
	(*cmd)[0] = 0;
	if ((int)ft_strlen(str) < pos)
		return (-1);
	start = 0;
	i = pos - 1;
	while (str[++i])
	{
		if (!(str[i] == 32 || (str[i] > 8 && str[i] < 14)))
		{
			start = 1;
			str_join_char(cmd, str[i]);
		}
		else if (start)
			return (i);
	}
	return (-1);
}
