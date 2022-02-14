/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:06:09 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 08:23:04 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_els_map(t_main_data *md, char *str, int *p)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			str[i] = '0';
		set_el_map(md, str[i], *p);
		*p += 1;
	}
	while (i < md->map.w)
	{
		set_el_map(md, '0', *p);
		*p += 1;
		i++;
	}
}

static void	set_size_map(t_main_data *md, char **map)
{
	int	i;
	int	len;

	i = -1;
	md->map.w = 0;
	md->map.h = 0;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (len < 0)
			prt_error(ERR_MAP_LN, 0);
		if (len > md->map.w)
			md->map.w = len;
		md->map.h++;
	}
}

void	set_map(t_main_data *md, char **map)
{
	int	i;
	int	pos;

	if (!map)
		prt_error(ERR_NULL_MAP, 0);
	set_size_map(md, map);
	md->map.el = malloc(sizeof(t_element_map) * md->map.w * md->map.h);
	if (!md->map.el)
		prt_error(ERR_MEM, 0);
	i = -1;
	pos = 0;
	while (map[++i])
	{
		set_els_map(md, map[i], &pos);
		free(map[i]);
	}
	free(map);
}
