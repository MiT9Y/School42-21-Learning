/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimon <msimon@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:09:37 by msimon            #+#    #+#             */
/*   Updated: 2021/12/05 07:01:59 by msimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ch_map_point(t_main_data *md, t_ipoint *ch_el,
							t_ipoint ***ch_arr, t_ipoint ***pro_arr)
{
	if ((get_map_el(md, ch_el->x - 1, ch_el->y)).type != '1')
		ch_and_add_el(md, (t_ipoint){ch_el->x - 1, ch_el->y}, ch_arr, pro_arr);
	if ((get_map_el(md, ch_el->x + 1, ch_el->y)).type != '1')
		ch_and_add_el(md, (t_ipoint){ch_el->x + 1, ch_el->y}, ch_arr, pro_arr);
	if ((get_map_el(md, ch_el->x, ch_el->y - 1)).type != '1')
		ch_and_add_el(md, (t_ipoint){ch_el->x, ch_el->y - 1}, ch_arr, pro_arr);
	if ((get_map_el(md, ch_el->x, ch_el->y + 1)).type != '1')
		ch_and_add_el(md, (t_ipoint){ch_el->x, ch_el->y + 1}, ch_arr, pro_arr);
}

static void	ch_contour(t_main_data *md)
{
	t_ipoint	**ch_arr;
	t_ipoint	**pro_arr;
	t_ipoint	*ch_el;
	int			i;

	ch_border_pos(md, (int)md->player.posx, (int)md->player.posy);
	init_arr((void ***)&ch_arr);
	init_arr((void ***)&pro_arr);
	add_arr_el((void ***)&ch_arr, sizeof(t_ipoint));
	ch_arr[0]->x = (int)md->player.posx;
	ch_arr[0]->y = (int)md->player.posy;
	i = arr_len((void **)ch_arr);
	while (i > 0)
	{
		ch_el = ch_arr[i - 1];
		ch_arr[i - 1] = NULL;
		ch_map_point(md, ch_el, &ch_arr, &pro_arr);
		i = add_arr_el((void ***)&pro_arr, sizeof(t_ipoint));
		pro_arr[i]->x = ch_el->x;
		pro_arr[i]->y = ch_el->y;
		free(ch_el);
		i = arr_len((void **)ch_arr);
	}
	drop_arr((void **)ch_arr);
	drop_arr((void **)pro_arr);
}

static void	edit_door(t_main_data *md, int i)
{
	t_ipoint	pos;

	pos.x = i % md->map.w;
	pos.y = i / md->map.w;
	if (pos.x < 1 || pos.x > md->map.w - 2
		|| pos.y < 1 || pos.y > md->map.h - 2)
		prt_error(ERR_DOOR_POS, 0);
	if ((get_map_el(md, pos.x - 1, pos.y)).type == '1'
		&& (get_map_el(md, pos.x + 1, pos.y)).type == '1')
		((t_door *) md->map.el[i].data)->dir = 0;
	else if ((get_map_el(md, pos.x, pos.y - 1)).type == '1'
		&& (get_map_el(md, pos.x, pos.y + 1)).type == '1')
		((t_door *) md->map.el[i].data)->dir = 1;
	else
		prt_error(ERR_DOOR_POS, 0);
	((t_door *) md->map.el[i].data)->x = pos.x;
	((t_door *) md->map.el[i].data)->y = pos.y;
}

void	ch_map(t_main_data *md)
{
	int			i;

	if (md->player.posa < -0.5)
		prt_error(ERR_PLR_POS, 0);
	if (!md->wall.n.src || !md->wall.e.src
		|| !md->wall.s.src || !md->wall.w.src)
		prt_error(ERR_NO_WALL, 0);
	i = -1;
	while (++i < md->map.w * md->map.h)
		if (md->map.el[i].type != '0' && md->map.el[i].type
			!= '1' && md->door_tex_arr)
			edit_door(md, i);
	ch_contour(md);
}
