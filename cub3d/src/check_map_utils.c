/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 08:39:45 by msimon            #+#    #+#             */
/*   Updated: 2021/12/04 15:06:04 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	ch_el_in_arr(int x, int y, t_ipoint **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		if (arr[i]->x == x && arr[i]->y == y)
			return (0);
	return (1);
}

void	ch_and_add_el(t_main_data *md, t_ipoint p,
						t_ipoint ***ch_arr, t_ipoint ***pro_arr)
{
	int	i;

	ch_border_pos(md, p.x, p.y);
	if (ch_el_in_arr(p.x, p.y, *ch_arr)
		&& ch_el_in_arr(p.x, p.y, *pro_arr))
	{
		i = add_arr_el((void ***)ch_arr, sizeof(t_ipoint));
		(*ch_arr)[i]->x = p.x;
		(*ch_arr)[i]->y = p.y;
	}
}

void	ch_border_pos(t_main_data *md, int x, int y)
{
	if (!x || x + 1 == md->map.w || !y || y + 1 == md->map.h)
		prt_error(ERR_CONTOUR, 0);
}

t_element_map	get_map_el(t_main_data *md, int x, int y)
{
	return (md->map.el[y * md->map.w + x]);
}
